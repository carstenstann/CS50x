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
    
    int change = round(amt*100);
    
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    
    while(change >= 25)
    {
        quarters++;
        change -= 25;
    }
    while(change >= 10)
    {
        dimes++;
        change -= 10;
    }
    while(change >= 5)
    {
        nickels++;
        change -=5;
    }
    while(change >= 1)
    {
        pennies++;
        change--;
    }
    
    int min_coins = quarters + dimes + nickels + pennies;
      
    printf("%i\n", min_coins);
}
