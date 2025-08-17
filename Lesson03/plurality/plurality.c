// https://cs50.harvard.edu/x/psets/3/plurality/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int ticket;
} candidate;

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("Usage: plurality [candidate ...]\n");
        return 0;
    }

    // preprocess
    int candidates_num = argc - 1;
    candidate *candidates = malloc(candidates_num * sizeof(candidate));
    if (candidates == NULL) {
        return 1;
    }
    memset(candidates, 0, candidates_num * sizeof(candidate));

    for (int i = 1; i < argc; i++) {
        char *name = argv[i];
        int name_len = strlen(name);

        char *name_copy = malloc(sizeof(char) * (name_len + 1));
        if (name_copy == NULL) {
            // error process;
        }
        strcpy(name_copy, name);
        candidates[i - 1].name = name_copy;
    }

    // vate
    int votes_num = get_int("Number of voters: ");
    int num = 0;
    do {
        int pos = -1;
        char *tmp = get_string("Vote:");
        for (int j = 0; j < candidates_num; j++) {
            if (strcmp(tmp, candidates[j].name) == 0) {
                pos = j;
                break;
            }
        }
        if (pos == -1) {
            printf("Invalid vote!\n");
        } else {
            candidates[pos].ticket += 1;
        }
        num++;
    } while (num < votes_num);

    int max = -1;
    for (int i = 0; i < candidates_num; i++) {
        if (max < candidates[i].ticket) {
            max = candidates[i].ticket;
        }
    }

    for (int i = 0; i < candidates_num; i++) {
        if (max == candidates[i].ticket) {
            printf("%s\n", candidates[i].name);
        }
    }

    return 0;
}