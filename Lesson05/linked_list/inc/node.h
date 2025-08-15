#ifndef NODE_H
#define NODE_H

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node *next;
} node;

void insert_node_at_head(node **head, node *target);
void free_nodes(node *head);
void print_nodes(node *head);

#endif