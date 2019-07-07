#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float amt;
    
    // Prompt user for amount
    do
    {
        amt = get_float("How much change is owed? ");
    }
    while(amt < 0);
    
    // Calculate total number of cents
    int change = round(amt*100);
    
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    
    // Calculate number of quarters needed
    while(change >= 25)
    {
        quarters++;
        change -= 25;
    }
    // Calculate number of dimes needed
    while(change >= 10)
    {
        dimes++;
        change -= 10;
    }
    // Calculate number of nickels needed
    while(change >= 5)
    {
        nickels++;
        change -=5;
    }
    // Calculate number of pennies needed
    while(change >= 1)
    {
        pennies++;
        change--;
    }
    
    // Sum number of coins
    int min_coins = quarters + dimes + nickels + pennies;
      
    printf("%i\n", min_coins);
}
