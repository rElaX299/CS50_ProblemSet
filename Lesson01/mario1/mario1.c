// https://cs50.harvard.edu/x/psets/1/mario/less/
#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int height;
    int ret;
    bool is_continue;
    do {
        is_continue = false;
        height = get_int("Height:");
        if (height == INT_MAX || height < 0) {
            printf("INVALID INPUT! TRY AGAIN.");
            is_continue = true;
        }
    } while (is_continue);
    
    for (int i = 0; i < height; i++) {
        for (int j = i; j < height - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}
