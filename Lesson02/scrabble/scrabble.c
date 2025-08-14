#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int get_score(char *str);
int parse_char(char c);

int main()
{
    char *player1_str = get_string("Player1: ");
    char *player2_str = get_string("Player2: ");
    int player1_score = get_score(player1_str);
    int player2_score = get_score(player2_str);

    if (player1_score > player2_score)
        printf("Player 1 wins!\n");
    else if (player1_score < player2_score)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

int get_score(char *str)
{
    int score = 0;
    for (int i = 0; i < strlen(str); i++) {
        score += parse_char(str[i]);
    }

    return score;
}

int parse_char(char c)
{
    int result = 0;
    if (isupper(c))
        result = POINTS[c - 'A'];
    else if (islower(c))
        result = POINTS[c - 'a'];
    return result;
}