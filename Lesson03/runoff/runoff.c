// https://cs50.harvard.edu/x/psets/3/plurality/

#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATE_CNT 9
#define MAX_RANK 3

struct candidate {
    char *name;
    int votes[MAX_RANK];
    bool is_eliminated;
};

struct candidate g_candidates[MAX_CANDIDATE_CNT];

int check_valid(int candidates_num);

void update_candidates_name(int cnt, char *name[]);
int parse_ticket();
bool vote(char *name, int rank);

void elect_winner(int standard);
void update_current_rank_votes(int *vote_cnt, int rank);
void print_winner_info(int *vote_cnt, int max);
int get_min_votes(int *vote_cnt);
int get_max_votes(int *vote_cnt);
void eliminate_candidate(int *vote_cnt, int min);

int main(int argc, char *argv[])
{
    int candidates_num = argc - 1;
    int ret = check_valid(candidates_num);
    if (ret != 0) {
        return ret;
    }

    update_candidates_name(candidates_num, argv + 1);

    int votes_num = get_int("Number of voters: ");
    if (votes_num == INT_MAX)
        return -1;
    for (int i = 0; i < votes_num; i++) {
        int ret = parse_ticket();
        if (ret != 0) {
            return ret;
        }
    }

    int win_standard = (votes_num + 1)/ 2;
    elect_winner(win_standard);

    return 0;
}

int check_valid(int candidates_num)
{
    if (candidates_num > MAX_CANDIDATE_CNT) {
        printf("Max candidate count is %d\n", MAX_CANDIDATE_CNT);
        return 2;
    }
    if (candidates_num == 0) {
        printf("Usage: plurality [candidate ...]\n");
        return 2;
    }
    return 0;
}

void update_candidates_name(int cnt, char *name[])
{
    memset(g_candidates, 0, MAX_CANDIDATE_CNT * sizeof(struct candidate));
    for (int i = 0; i < cnt; i++) {
        g_candidates[i].name = name[i];
    }
}

int parse_ticket()
{
    for (int rank = 0; rank < MAX_RANK; rank++) {
        char *name = get_string("Rank %d:", rank + 1);
        if (name == NULL)
            return -1;
    
        if (!vote(name, rank)) {
            printf("Invalid vote!\n");
            return 1;
        }
    }
    printf("\n");
    return 0;
}

bool vote(char *name, int rank)
{
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (strcmp(name, g_candidates[i].name) == 0) {
            g_candidates[i].votes[rank]++;
            return true;
        }
    }
    return false;
}

void elect_winner(int standard)
{
    for (int rank = 0; rank < MAX_RANK; rank++) {
        int vote_cnt[MAX_CANDIDATE_CNT] = {0};
        update_current_rank_votes(vote_cnt, rank);

        int max = get_max_votes(vote_cnt);
        int min = get_min_votes(vote_cnt);

        if (max >= standard) {
            print_winner_info(vote_cnt, max);
            return;
        }

        eliminate_candidate(vote_cnt, min);
    }
}

void update_current_rank_votes(int *vote_cnt, int rank)
{
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (g_candidates[i].is_eliminated)
            continue;
        for (int j = 0; j <= rank; j++)
            vote_cnt[i] += g_candidates[i].votes[j];
    }
}

int get_min_votes(int *vote_cnt)
{
    int min = INT_MAX;
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (g_candidates[i].is_eliminated)
            continue;
        if (min > vote_cnt[i])
            min = vote_cnt[i];
    }
    return min;
}

int get_max_votes(int *vote_cnt)
{
    int max = -1;
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (g_candidates[i].is_eliminated)
            continue;
        if (max < vote_cnt[i])
            max = vote_cnt[i];
    }
    return max;
}

void print_winner_info(int *vote_cnt, int max)
{
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (max == vote_cnt[i])
            printf("%s\n", g_candidates[i].name);
    }
}

void eliminate_candidate(int *vote_cnt, int min)
{
    for (int i = 0; i < MAX_CANDIDATE_CNT && g_candidates[i].name != NULL; i++) {
        if (min == vote_cnt[i] && !g_candidates[i].is_eliminated) {
            for (int j = 0; j < MAX_RANK; j++)
                g_candidates[i].is_eliminated = true;
        }
    }
}