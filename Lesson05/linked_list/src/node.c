#include <node.h>


void print_nodes(node *head)
{
    printf("Current list: ");
    for (node *ptr = head; ptr != NULL; ptr = ptr->next) {
        printf("%d ", ptr->val);
    }
    printf("\n");
}

void free_nodes(node *head)
{
    node *ptr = head;
    while (ptr != NULL) {
        node *tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
