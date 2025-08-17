// https://cs50.harvard.edu/x/psets/3/plurality/

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATE_CNT 9

typedef struct {
    char *name;
    int votes;
} candidate;

candidate g_candidates[MAX_CANDIDATE_CNT];

bool vote(char *name);
void print_winner();

int main(int argc, char *argv[])
{
    // preprocess
    int candidates_num = argc - 1;
    if (candidates_num > MAX_CANDIDATE_CNT) {
        printf("Max candidate count is %d\n", MAX_CANDIDATE_CNT);
        return 2;
    }
    if (candidates_num == 0) {
        printf("Usage: plurality [candidate ...]\n");
        return 2;
    }

    memset(g_candidates, 0, MAX_CANDIDATE_CNT * sizeof(candidate));

    for (int i = 1; i < argc; i++)
        g_candidates[i - 1].name = argv[i];

    // vote
    int votes_num = get_int("Number of voters: ");
    if (votes_num == INT_MAX)
        return -1;
    do {
        char *name = get_string("Vote:");
        if (name == NULL)
            return -1;
        
        if (!vote(name)) {
            printf("Invalid vote!\n");
            return 1;
        }
    } while (votes_num--);

    print_winner();

    return 0;
}

bool vote(char *name)
{
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (strcmp(name, g_candidates[i].name) == 0) {
            g_candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner()
{
    int max = -1;
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (max < g_candidates[i].votes)
            max = g_candidates[i].votes;
    }

    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (max == g_candidates[i].votes)
            printf("%s\n", g_candidates[i].name);
    }    
}