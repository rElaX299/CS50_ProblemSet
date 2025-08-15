#include <list.h>

int init_list(list *l, int capacity, int *init_val)
{
    node *my_list = NULL;

    for (int i = 0; i < capacity; i++) {
        // init tmp node n
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            free_nodes(my_list);
            return ERROR;
        }
        new_node->val = init_val[i];
        new_node->next = NULL;

        insert_node_at_head(&my_list, new_node);
    }
    l->nodes = my_list;
    l->capacity = capacity;
    l->size = capacity;

    return SUCCESS;
}

void delete_list(list *l)
{
    if (l == NULL)
        return;

    if (l->nodes == NULL) {
        free(l);
        return;
    }

    free_nodes(l->nodes);
    free(l);
}

int insert_num(list *l, int val)
{
    if (l->capacity == l->size) {
        l->capacity += 1;
    }
    l->size += 1;

    // Create new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        return ERROR;
    }
    new_node->val = val;
    new_node->next = NULL;

    node *head = l->nodes;
    // At head
    if (new_node->val > head->val) {
        insert_node_at_head(&head, new_node);
        l->nodes = head;
        return SUCCESS;
    }
    for (node *ptr = head; ptr != NULL; ptr=ptr->next) {
        // At tail
        if (ptr->next == NULL) {
            ptr->next = new_node;
            break;
        }

        // In the middle
        if (ptr->val > new_node->val && ptr->next->val < new_node->val) {
            new_node->next = ptr->next;
            ptr->next = new_node;
            break;
        }
    }

    return SUCCESS;
}

int delete_num(list *l, int val)
{
    if (l->size == 0) {
        return ERROR;
    }
    l->size -= 1;

    node *head = l->nodes;
    if (head->val == val) {
        l->nodes = head->next;
        free(head);
        return SUCCESS;
    }

    for (node *ptr = head; ptr != NULL; ptr=ptr->next) {
        if (ptr->val == val) {
            node *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
            return SUCCESS;
        }
    }

    return ERROR;
}

int search_num(list *l, int val)
{
    node *head = l->nodes;
    int pos = 0;
    for (node *ptr = head; ptr != NULL; ptr=ptr->next) {
        pos += 1;
        if (ptr->val == val) {
            return pos;
        }
    }
    return -1;
}
