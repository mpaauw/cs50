#include <stdio.h>
#include <cs50.h>
#include <math.h>

int get_input(void);
int process_coins(int change, int numCoins);

int main(void)
{
    printf("%i\n", process_coins(get_input(), 0));
    return 0;
}

int get_input(void)
{
    float input;
    do
    {
        input = get_float("Change owed: ");
    } while(input < 0);
    return round(input * 100); // normalize change to an integer value in order to avoid imprecision.
}

// recursively process coin denominations:
int process_coins(int change, int numCoins)
{
    // base case:
    if(change == 0)
    {
        return numCoins;
    }
    
    // greedily assess coin distribution for remaining change amount:
    if(change % 25 != change)
    {
        return process_coins(change % 25, numCoins += (change / 25));
    }
    else if(change % 10 != change)
    {
        return process_coins(change % 10, numCoins += (change / 10));
    }
    else if(change % 5 != change)
    {
        return process_coins(change % 5, numCoins += (change / 5));
    }
    else
    {
        return process_coins(change % 1, numCoins += (change / 1));
    }
}
