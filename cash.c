#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollar;
    do
    {
        dollar = get_float("Change owed: ");
    }
    while (dollar < 0);

    int cents = round(dollar * 100);
    int coins = 0;
    int values[4] = {25, 10, 5, 1};

    for (int i = 0; i < 4; i++)
    {
        coins += cents / values[i];
        cents %= values[i];
    }

    printf("%d\n", coins);
}

