#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define ERROR   1

typedef struct node {
    int val;
    struct node *next;
} node;

typedef struct list {
    int capacity;
    int size;
    node *nodes;
} list;

int init_list(list *l, int capacity, int *init_val);
int insert_num(list *l, int val);
int delete_num(list *l, int val);
int search_num(list *l, int val);

void insert_node_at_head(node **head, node *target);
void free_nodes(node *head);
void print_nodes(node *head);

int main()
{
    int ret;
    list *l = malloc(sizeof(list));
    if (l == NULL) {
        return ERROR;
    }

    int capacity = get_int("Capacity: ");
    int *init_val = malloc(capacity * sizeof(int));
    if (init_val == NULL) {
        free(l);
        return ERROR;
    }

    for (int i = 0; i < capacity; i++) {
        init_val[i] = get_int("Number: ");
    }
    
    ret = init_list(l, capacity, init_val);
    if (ret != SUCCESS) {
        free(l);
        free(init_val);
        return ret;
    }
    free(init_val);

    print_nodes(l->nodes);

    // int val = get_int("Insert Number: ");
    // ret = insert_num(l, val);
    // print_nodes(l->nodes);


    // val = get_int("Search Number: ");
    // ret = search_num(l, val);
    // if (ret > 0) {
    //     printf("Find at %d pos.\n", ret);
    // } else {
    //     printf("Not found.\n");
    // }
    // print_nodes(l->nodes);

    int val = get_int("Delete Number: ");
    ret = delete_num(l, val);
    print_nodes(l->nodes);

    // val = get_int("Insert Number: ");
    // ret = insert_num(l, val);
    // print_nodes(l->nodes);


    free_nodes(l->nodes);
    free(l);

    
    return SUCCESS;
}

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
    }

    for (node *ptr = head; ptr != NULL; ptr=ptr->next) {
        if (ptr->val == val) {
            node *tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }

    return SUCCESS;
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