#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <common.h>
#include <list.h>

const char *hint = "Please input operation:\n"   \
                    "1. Insert a number.\n"       \
                    "2. Delete a number.\n"       \
                    "3. Search a number.\n"       \
                    "0. Quit.\n"                  \
                    "Operation: ";

int init_my_list(list *l)
{
    int ret;
    l = malloc(sizeof(list));
    if (l == NULL) {
        return ERROR;
    }

    int capacity = get_int("Capacity: ");
    int *init_val = malloc(capacity * sizeof(int));
    if (init_val == NULL) {
        delete_list(l);
        return ERROR;
    }

    for (int i = 0; i < capacity; i++) {
        init_val[i] = get_int("Number: ");
    }

    ret = init_list(l, capacity, init_val);
    if (ret != SUCCESS) {
        delete_list(l);
        free(init_val);
        return ret;
    }
    free(init_val);

    print_nodes(l->nodes);
    return SUCCESS;
}


void delete_my_list(list *l)
{
    free_nodes(l->nodes);
    free(l);
}

int insert_num_in_my_list(list *l)
{
    int val = get_int("Insert Number: ");
    int ret = insert_num(l, val);
    print_nodes(l->nodes);
    return ret;
}

int delete_num_in_my_list(list *l)
{
    int val = get_int("Delete Number: ");
    int ret = delete_num(l, val);
    if (ret == NOT_FOUND) {
        printf("Not found.\n");
    } else if (ret == SUCCESS) {
        printf("Deleted.\n");
    } else {
        printf("Error: %d\n", ret);
        delete_list(l);
    }
    return ret;
}

int search_num_in_my_list(list *l)
{
    int val = get_int("Search Number: ");
    int ret = search_num(l, val);
    if (ret > 0) {
        printf("Find at %d pos.\n", ret);
    } else {
        printf("Not found.\n");
    }
    print_nodes(l->nodes);
    return ret;
}


int execute_operation(list *l, int op)
{
    int ret = SUCCESS;
    switch (op)
    {
    case 0:
        /* code */
        delete_my_list(l);
        break;
    case 1:
        /* code */
        ret = insert_num_in_my_list(l);
        break;
    case 2:
        /* code */
        ret = delete_num_in_my_list(l);
        break;
    case 3:
        ret = search_num_in_my_list(l);
        /* code */
        break;
    default:
        break;
    }
    return ret;
}

int main()
{
    int ret;
    list *l = NULL;
    ret = init_my_list(l);
    if (ret != SUCCESS) {
        return ret;
    }

    int op;
    do {
        op = get_int("\n%s", hint);
        ret = execute_operation(l, op);

    } while (op != 0);
    
    return SUCCESS;
}
