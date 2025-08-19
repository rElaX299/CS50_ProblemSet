#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <common.h>
#include <list.h>

const char *hint = "Please select operation:\n"   \
                    "1. Insert a number.\n"       \
                    "2. Delete a number.\n"       \
                    "3. Search a number.\n"       \
                    "0. Quit.\n"                  \
                    "Operation: ";

list* init_my_list()
{
    int ret;
    list *l = malloc(sizeof(list));
    if (l == NULL) {
        return NULL;
    }

    int capacity = get_int("Capacity: ");

    ret = init_list(l, capacity);
    if (ret != SUCCESS) {
        free(l);
        return NULL;
    }

    print_nodes(l->nodes);
    return l;
}


int delete_my_list(list *l)
{
    int ret = delete_list(l);
    if (ret == SUCCESS) {
        printf("DELETE: delete success.\n");
        return SUCCESS;
    }
    return ERROR;
}

int insert_num_in_my_list(list *l)
{
    int val = get_int("Insert Number: ");
    int ret = insert_num(l, val);
    if (ret == SUCCESS) {
        printf("INSERT: insert success.\n");
    }
    if (ret == ERROR) {
        printf("INSERT: ERROR.\n");
        return ERROR;
    }
    if (ret == RET_LIST_FULL) {
        printf("INSERT: list is full.\n");
    }
    print_nodes(l->nodes);
    return SUCCESS;
}

int delete_num_in_my_list(list *l)
{
    int val = get_int("Delete Number: ");
    int ret = delete_num(l, val);
    if (ret == SUCCESS) {
        printf("DELETE: delete success.\n");
    }
    if (ret == RET_NUM_NOT_FOUND) {
        printf("DELETE: val not found.\n");
    }
    if (ret == RET_LIST_EMPTY) {
        printf("DELETE: list is empty.\n");
    }

    print_nodes(l->nodes);
    return SUCCESS;
}

int search_num_in_my_list(list *l)
{
    int val = get_int("Search Number: ");
    int ret = search_num(l, val);
    if (ret == RET_NUM_NOT_FOUND) {
        printf("SEARCH: not found.\n");
    } else {
        printf("SEARCH: find at %d pos.\n", ret);
    }
    print_nodes(l->nodes);
    return SUCCESS;
}

typedef enum {
    OP_INSERT = 1,
    OP_DELETE = 2,
    OP_SEARCH = 3,
    OP_RESIZE = 4,
    OP_QUIT   = 0
} OP;

int execute_operation(list *l, int op)
{
    int ret = SUCCESS;
    switch (op)
    {
    case OP_INSERT:
        ret = insert_num_in_my_list(l);
        break;
    case OP_DELETE:
        ret = delete_num_in_my_list(l);
        break;
    case OP_SEARCH:
        ret = search_num_in_my_list(l);
        break;
    case OP_QUIT:
        ret = delete_my_list(l);
        break;
    default:
        break;
    }
    if (ret != SUCCESS) {
        if (l == NULL) {
            return ERROR;
        }
        delete_my_list(l);
        return ERROR;
    }
    return SUCCESS;
}

int main()
{
    int ret;
    list *l = init_my_list();
    if (l == NULL) {
        return ERROR;
    }

    int op;
    do {
        op = get_int("\n%s", hint);
        ret = execute_operation(l, op);
        if (ret != SUCCESS) {
            return ERROR;
        }
    } while (op != OP_QUIT);

    return SUCCESS;
}
