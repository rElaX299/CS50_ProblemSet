// https://cs50.harvard.edu/x/psets/1/mario/less/
#include <stdio.h>

int main(void)
{
    printf("Height:");
    int height;
    scanf("%d", &height);
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
