#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
        printf("Tie!");
}

int get_score(char *str)
{
    int score = 0;
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c >= 'A' && c <= 'Z') {
            c = c - ('A' - 'a');
        }
        score += parse_char(c);
    }

    return score;
}

int parse_char(char c)
{
    int result = 0;
    switch (c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'l':
        case 'n':
        case 'o':
        case 'r':
        case 's':
        case 't':
        case 'u':
            return 1;
        case 'd':
        case 'g':
            return 2;
        case 'b':
        case 'c':
        case 'm':
        case 'p':
            return 3;
        case 'f':
        case 'h':
        case 'v':
        case 'w':
        case 'y':
            return 4;
        case 'k':
            return 5;
        case 'j':
        case 'x':
            return 8;
        case 'q':
        case 'z':
            return 10;
        default:
            break;
    }
    return 0;
}