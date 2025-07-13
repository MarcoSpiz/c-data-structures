/*
 *    LinkedList implementation.
 *    The LinkedList implement either reference to head and tail for
 *    optimizing insert at start and at end of list.
 *
 *    The implementation provide this API:
 *      - init_linkedlist(): initialized list to NULL;
 *      - add_element_at_start(LinkedList *ll, void *value): add element at start of the list;
 *      - add_element_at_end(LinkedList *ll, void *value): add element at end of the list;
 *      - add_element_at_index(const LinkedList *ll, void *value, const int index): add element at given index;
 *      - delete_element(LinkedList *ll, const void *value, ComparatorFunc comparator): delete the first occurrence
 *              of the given value based callback function;
 *      - delete_element_at_index(LinkedList *ll, const int index): delete element at given index;
 *      - find_element(const LinkedList *ll, const void *value, ComparatorFunc comparator, int *index_element): find element based on value;
 *      - get_element_at_index(const LinkedList *ll, const int index, void *out_value): write the value of the element at index in out_value;
 *      - size(const LinkedList *ll): return the length of the list;
 *      - clear(LinkedList *ll): dump the element of the list.
 *
 *      TODO: add count int LinkedList struct to keep the dimension of the list (func size() become O(1))
 *            and used it internally to check corner case
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"


/* initialized LinkedList */
LinkedList init_linkedlist() {
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    return list;
}


/* Add element at start of linked list*/
void add_element_at_start(LinkedList *ll, void *value) {
    if (ll == NULL) return;
    Element *new_element = malloc(sizeof(Element));
    if (!new_element) {
        fprintf(stderr, "error: unable to alloc memory");
        return;
    }
    // empty list, set new element as head and tail of list
    if (ll->head == NULL || ll->tail == NULL) {
        ll->head = new_element;
        ll->tail = new_element;
        new_element->value = value;
        new_element->next = NULL;
        return;
    }
    Element *tmp = ll->head;
    new_element->value = value;
    new_element->next = tmp;
    ll->head = new_element;
}

/* add element at end of linked list */
void add_element_at_end(LinkedList *ll, void *value) {
    if (ll == NULL) return;
    Element *new_element = malloc(sizeof(Element));
    if (!new_element) {
        fprintf(stderr, "error: unable to alloc memory");
        return;
    }
    new_element->value = value;
    new_element->next = NULL;
    if (ll->head == NULL || ll->tail == NULL) {
        ll->head = new_element;
        ll->tail = new_element;
        return;
    }
    Element *tail = ll->tail;
    tail->next = new_element;
    ll->tail = new_element;
}

/* add element in LinkedList at given index*/
void add_element_at_index(LinkedList *ll, void *value, const int index) {
    if (index < 0) return;
    if (ll == NULL) return;
    Element *current = ll->head;
    Element *previous = ll->head;
    int count = 0;
    while (current) {
        if (count == index) {
            Element *new = malloc(sizeof(Element));
            if (!new) {
                fprintf(stderr, "error: unable to alloc memory");
                return;
            }
            new->value = value;
            Element *tmp = current->next;
            new->next = tmp;
            previous->next = new;
            return;
        }
        count++;
        previous = current;
        current = current->next;
    }
}

/* Delete first occurrence of value in the LinkedList*/
void delete_element(LinkedList *ll, const void *value, ComparatorFunc comparator) {
    if (ll == NULL || ll->head == NULL) return;
    if (comparator == NULL) {
        fprintf(stderr, "Error: comparator can not be null, please provide one");
        return;
    }
    // special case, value is the head element
    if (comparator(ll->head->value, value) == 0) {
        Element *temp = ll->head;
        ll->head = ll->head->next;

        free(temp);
        return;
    }
    Element *current = ll->head;
    Element *previous = ll->head;
    while (current) {
        if (comparator(current->value, value) == 0) {
            previous->next = current->next;
            if (current->next == NULL) {
                ll->tail = previous;
            }

            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

/* Remove element at given index, used 0-index */
void delete_element_at_index(LinkedList *ll, const int index) {
    if (index < 0) return;
    if (ll == NULL || ll->head == NULL) return;
    if (index == 0) {
        Element *temp = ll->head;
        ll->head = ll->head->next;
        if (ll->tail == temp) {
            ll->tail = NULL;
        }

        free(temp);
        return;
    }
    Element *current = ll->head;
    Element *previous = ll->head;
    int count = 0;
    while (current) {
        if (count == index) {
            previous->next = current->next;
            if (current->next == NULL) {
                ll->tail = previous;
            }

            free(current);
            return;
        }
        count++;
        previous = current;
        current = current->next;
    }
}

/* Find head occurrence of value in the LinkedList,
 * set params index_element to the index of element
 * return 1 if it's find otherwise 0*/
int find_element(const LinkedList *ll, const void *value, ComparatorFunc comparator, int *index_element) {
    if (comparator == NULL) {
        fprintf(stderr, "Error: comparator can not be null, please provide one");
        return ERROR;
    }
    // empty list
    if (ll->head == NULL) return 0;
    Element *current = ll->head;
    int count = 0;
    while (current) {
        if (comparator(current->value, value) == 0) {
            *index_element = count;
            return SUCCESS;
        };
        current = current->next;
        count++;
    }
    return NO_OUTPUT;
}

/* Write value at given index, used 0-index*/
int get_element_at_index(const LinkedList *ll, const int index, void *out_value) {
    if (index < 0) return ERROR;
    if (ll == NULL || ll->head == NULL) return ERROR;
    if (index == 0) {
        *(void **) out_value = ll->head->value;
        return SUCCESS;
    }
    Element *current = ll->head;
    int count = 0;
    while (current) {
        if (count == index) {
            *(void **) out_value = current->value;
            return SUCCESS;
        }
        count++;
        current = current->next;
    }
    return NO_OUTPUT;
}

/* return the length of LinkedList*/
int size(const LinkedList *ll) {
    if (ll == NULL || ll->head == NULL) return 0;
    Element *current = ll->head;
    int count = 0;
    while (current) {
        current = current->next;
        count++;
    }
    return count;
}

/* clear the LinkedList*/
void clear(LinkedList *ll) {
    if (ll == NULL || ll->head == NULL) return;
    Element *current = ll->head;
    while (current) {
        Element *next = current->next;
        free(current);
        current = next;
    }
    ll->head = NULL;
    ll->tail = NULL;
}
