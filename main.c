#include <stdio.h>
#include <stdlib.h>
#include "linkedlist/linkedlist.h"


int compareInt(const void *first_value, const void *second_value) {
    const int *value_f = first_value;
    const int *value_s = second_value;
    if (*value_f == *value_s) return 0;
    return (*value_f < *value_s) ? -1 : 1;
}

/* Need to write own comparator if you want to use different data type*/
int main() {
    LinkedList list = init_linkedlist();

    for (int i = 0; i < 10; i++) {
        int *k = malloc(sizeof(int));
        *k = 12 + i;
        add_element_at_end(&list, k);
    }

    Element *current = list.head;
    while (current) {
        int *val = current->value;
        printf("%d\n", *val);
        current = current->next;
    }

    // free memory
    clear(&list);
    return 0;
}
