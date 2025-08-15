#ifndef LIST_H
#define LIST_H

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include <common.h>
#include <node.h>

typedef struct list {
    int capacity;
    int size;
    node *nodes;
} list;

int init_list(list *l, int capacity, int *init_val);
void delete_list(list *l);
int insert_num(list *l, int val);
int delete_num(list *l, int val);
int search_num(list *l, int val);

#endif