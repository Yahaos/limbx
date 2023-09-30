#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst == NULL || lst->next == NULL) {
        return lst;
    }
    t_list *left = lst;
    t_list *right = lst->next;
    left->next = NULL;

    while (right != NULL) {
        t_list *temp = right->next;
        if (cmp(left->data, right->data)) {
            right->next = left;
            left = right;
        } else {
            t_list *prev = left;
            t_list *current = left->next;

            while (current != NULL && cmp(current->data, right->data)) {
                prev = current;
                current = current->next;
            }
            prev->next = right;
            right->next = current;
        }
        right = temp;
    }
    return left;
}
