// https://cs50.harvard.edu/x/psets/1/credit/
#include <cs50.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


/* Here assume enum has associated with string, maybe should use dict instead.
   But it is hard to use dict in c, so why not just use Python. :) */ 
typedef enum {
    TYPE_AMEX =       0,
    TYPE_MASTERCARD = 1,
    TYPE_VISA =       2,
    TYPE_INVALID =    3,
} TYPE;

const char *TYPE_STR[] = {
    "AMEX\n",
    "MASTERCARD\n",
    "VISA\n",
    "INVALID\n",
};

const long MAX_VALID_CARD_NUMBER = 10000000000000000;
const long MIN_VALID_CARD_NUMBER = 1000000000000;

int get_credit_type(int prefix);
bool is_valid_number(long card_number); 

int main()
{
    long card_number = get_long("Number: ");
    if (card_number == LONG_MAX) {
        printf("%s", TYPE_STR[TYPE_INVALID]);
        return 0;
    }

    if (card_number < MIN_VALID_CARD_NUMBER || card_number > MAX_VALID_CARD_NUMBER) {
        printf("%s", TYPE_STR[TYPE_INVALID]);
        return 0;
    }

    if (!is_valid_number(card_number)) {
        printf("%s", TYPE_STR[TYPE_INVALID]);
        return 0;
    }

    char card_number_str[20];
    sprintf(card_number_str, "%ld", card_number);

    int prefix = 10 * (card_number_str[0] - '0') + (card_number_str[1] - '0');
    int type = get_credit_type(prefix);
    printf("%s", TYPE_STR[type]);

    return 0;
}

int get_credit_type(int prefix)
{
    switch (prefix)
    {
        case 34:
        case 37:
            return TYPE_AMEX;
            break;
        case 22:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            return TYPE_MASTERCARD;
            break;
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:
        case 49:
            return TYPE_VISA;
            break;
        default:
            break;
    }
    return TYPE_INVALID;
}

bool is_valid_number(long card_number)
{
    bool is_odd = true;
    int result = 0;
    while (card_number) {
        int remain = card_number % 10;
        if (is_odd) {
            result += remain;
            is_odd = false;
        } else {
            int tmp = remain * 2;
            result += tmp % 10;
            result += tmp / 10;
            is_odd = true;
        }
        card_number /= 10;
    }

    return result % 10 == 0 ? true : false;
}