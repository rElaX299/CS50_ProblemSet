#include <cs50.h>
#include <stdio.h>

const int coins_type = 4;
const int coins[] = {25, 10, 5, 1};

int main(void)
{
    int change;
    int min_need_coins = 0;
    do {
        change = get_int("Change owed:");
    } while (change < 0 || change == INT_MAX);

    for (int i = 0; i < coins_type; i++) {
        int cur_max_coin = coins[i];
        min_need_coins += change / cur_max_coin;
        change %= cur_max_coin;
        if (change <= 0)
            break;
    }

    printf("%d\n", min_need_coins);
}