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
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define SUCCESS 1
#define NO_OUTPUT 0
#define ERROR (-1)


/* This struct model the single element of LinkedList*/
typedef struct Element {
    void *value; // value of the element
    struct Element *next; // pointer to the next element
} Element;

/* This struct model the LinkedList */
typedef struct {
    Element *head; // pointer to the first element
    Element *tail; // pointer to the last element, to increase performance to add element at end
} LinkedList;

/* Function type of comparator */
typedef int (*ComparatorFunc)(const void *a, const void *b);

/* Initialize LinkedList*/
LinkedList init_linkedlist();

/* Add element at start of linked list */
void add_element_at_start(LinkedList *ll, void *value);

/* Add element at end of linked list */
void add_element_at_end(LinkedList *ll, void *value);

/* Add element in LinkedList at given index*/
void add_element_at_index(LinkedList *ll, void *value, const int index);

/* Delete first occurrence of value in the LinkedList*/
void delete_element(LinkedList *ll, const void *value, ComparatorFunc comparator);

/* Remove element at given index, used 0-index */
void delete_element_at_index(LinkedList *ll, const int index);

/* Find head occurrence of value in the LinkedList,
 * set params index_element to the index of element
 * return 1 if it's find otherwise 0*/
int find_element(const LinkedList *ll, const void *value, ComparatorFunc comparator, int *index_element);

/* Write value at given index, used 0-index*/
int get_element_at_index(const LinkedList *ll, const int index, void *out_value);

/* return the length of LinkedList*/
int size(const LinkedList *ll);

/* clear the LinkedList*/
void clear(LinkedList *ll);
#endif //LINKEDLIST_H
