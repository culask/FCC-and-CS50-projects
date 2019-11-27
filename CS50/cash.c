#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    int cents = round(dollars * 100);
    int coins = 0;
    coins += cents / 25;
    coins += (cents % 25) / 10;
    coins += ((cents % 25) % 10) / 5;
    coins += (((cents % 25) % 10) % 5);
    printf("%i\n", coins);
}
