#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include <common.h>
#include <list.h>


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
    if (ret == NOT_FOUND) {
        printf("Not found.\n");
    } else if (ret == SUCCESS) {
        printf("Deleted.\n");
    } else {
        printf("Error: %d\n", ret);
        delete_list(l);
        return ret;
    }
    print_nodes(l->nodes);

    // val = get_int("Insert Number: ");
    // ret = insert_num(l, val);
    // print_nodes(l->nodes);


    free_nodes(l->nodes);
    free(l);


    return SUCCESS;
}
