// https://cs50.harvard.edu/x/psets/1/mario/more/
#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool is_valid_input(int height);

int main(void)
{
    int height;

    do {
        height = get_int("Height:");
    } while (!is_valid_input(height));
    
    for (int i = 0; i < height; i++) {
        for (int j = i; j < height - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf(" ");
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        for (int j = i; j < height - 1; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

bool is_valid_input(int height)
{
    if (height == INT_MAX)
        return false;
    if (height <= 0 || height > 8)
        return false;
    return true;
}