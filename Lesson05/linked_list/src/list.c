#include <list.h>

int init_list(list *l, int capacity)
{
    if (l == NULL) {
        return ERROR;
    }
    l->nodes = NULL;
    l->capacity = capacity;
    l->size = 0;
    return SUCCESS;
}

int resize_list(list *l, int capacity)
{
    if (l == NULL || l->size > capacity) {
        return ERROR;
    }
    l->capacity = capacity;
    return SUCCESS;
}

int delete_list(list *l)
{
    if (l == NULL)
        return ERROR;

    if (l->nodes == NULL) {
        free(l);
        return SUCCESS;
    }

    free_nodes(l->nodes);
    free(l);
    return SUCCESS;
}

int insert_num(list *l, int val)
{
    if (l->capacity == l->size) {
        goto LIST_FULL_EXIT;
    }
    
    // Create new node
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        goto ERROR_EXIT;
    }
    new_node->val = val;
    new_node->next = NULL;

    node *head = l->nodes;
    // First num
    if (head == NULL) {
        l->nodes = new_node;
        goto SUCCESS_EXIT;
    }
    // At head
    if (new_node->val > head->val) {
        new_node->next = head;
        l->nodes = new_node;
        goto SUCCESS_EXIT;
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
    goto SUCCESS_EXIT;

    SUCCESS_EXIT:
    l->size += 1;
    return SUCCESS;

    LIST_FULL_EXIT:
    return RET_LIST_FULL;
    
    ERROR_EXIT:
    return ERROR;
}

int delete_num(list *l, int val)
{
    if (l->size == 0) {
        goto LIST_EMPTY_EXIT;
    }
    

    node *head = l->nodes;
    // At head
    if (head->val == val) {
        l->nodes = head->next;
        free(head);
        goto SUCCESS_EXIT;
    }

    // Here use ptr->next->next cause we can only delete ptr->next and then connect ptr and ptr->next->next.
    // If use ptr itself, we can connect ptr->prev and ptr->next.
    for (node *ptr = head; ptr->next != NULL; ptr=ptr->next) {
        if (ptr->next->val == val) {
            // At tail
            if (ptr->next->next == NULL) {
                free(ptr->next);
                ptr->next = NULL;
                goto SUCCESS_EXIT;
            }
            node *tmp = ptr->next;
            ptr->next = ptr->next->next;
            free(tmp);
            goto SUCCESS_EXIT;
        }
    }

    goto NOT_FOUND_EXIT;

    SUCCESS_EXIT:
    l->size -= 1;
    return SUCCESS;

    LIST_EMPTY_EXIT:
    return RET_LIST_EMPTY;

    NOT_FOUND_EXIT:
    return RET_NUM_NOT_FOUND;
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
    return RET_NUM_NOT_FOUND;
}
