#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int digits = 2;                             //Creating integer for counting digits;assigning as two because two first digits will not be counted
    long credit = get_long("Number:");          //Prompting user for number
    long credit1 = credit;                      //Assigning number entered into another variable
   
    while (credit > 100)                        //Counting amount of digits and calculating first 2 digits
    {
        credit /= 10;     
        digits++;
    }
    
    int sum = 0;                                //Applying Luhns algorithm loop
    for (int i = 1; i <= digits; i++)
    {
        int digit = credit1 % 10;
        if (i % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        credit1 /= 10;
    }
    
    sum %= 10;                                                      //Checking if sum is divisible by 10
    
    if (digits == 15 && (credit == 34 || credit == 37) && sum == 0)    //Checking if AMEX
    {
        printf("AMEX\n");
    }
    
    else if (digits == 16 && credit > 50 && credit < 56 && sum == 0)        //Checking if Mastercard
    {
        printf("MASTERCARD\n");
    }
        

    else if ((digits == 13 || digits == 16) && (credit / 10 == 4) && sum == 0) //Checking if VISA
    {
        printf("VISA\n");
    }
    
    else 
    {
        printf("INVALID\n");
    }
}