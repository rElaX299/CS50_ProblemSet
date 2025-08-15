#include <node.h>

void insert_node_at_head(node **head, node *target)
{
    node *ptr = *head;
    *head = target;
    (*head)->next = ptr;
}

void print_nodes(node *head)
{
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
