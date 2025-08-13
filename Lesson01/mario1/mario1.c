// https://cs50.harvard.edu/x/psets/1/mario/less/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int height;
    int ret;
    bool is_continue;
    do {
        is_continue = false;
        printf("Height:");
        ret = scanf("%d", &height);
        if (ret != 1) {
            printf("INVALID INPUT!");
            is_continue = true;
        }
        if (height < 0) {
            printf("NOT VALID NUMBER!");
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
