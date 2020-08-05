#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare and initialize a variable and ask for user input.
    long cardnumber = 0;
 
    // Ask for credit card number  
    do
    {
        cardnumber = get_long("What is your card number? \n");
    }
    while (cardnumber < 0);

    // Determine whether it has a valid number of digits
    int count = 0;
    long long digits = cardnumber;
    
    while (digits > 0)
    {
        digits = digits / 10;
        count++;
    }
    
    if ((count != 13) && (count != 15) && (count != 16))
    {
        printf("INVALID\n");
    }
    
    int number[count];
    
    // Storing a cardnumber in an array "number" with size "count".
    for (int i = 0; i < count; i++)
    {
        number[i] = cardnumber % 10;
        cardnumber = cardnumber / 10;
    }
    
    int originalnumber[count];
    
    // Storing a cardnumber into an array "originalnumber" from its second-to-last digit.
    for (int i = 1; i < count; i++)
    {
        originalnumber[i] = number[i];
    }
    
    // Adding the product of every other digit, starting with the number’s second-to-last digit.
    for (int i = 1; i < count; i+=2)
    {
        number[i] = number[i] * 2;
    }
    
    int v = 0;
    
    int temp;
    
    // Checking for Visa - 13 or 16 digits, starts with 4.
    if (count == 13)
    {
        // Adding the digits multiplied by 2 from second last digits and remaining digits which are not multiplied by 2.
        // i.e. If suppose we get 14 after multiplying the 4th digit by 2, than first part will be 4 (number[i] % 10) 
        // and the second part will be 1(number[i]/10 % 10) i.e. 4+1= 5 (sum of 14).
        for (int i = 0; i < count; i++)
        {
            temp = (number[i] % 10) + (number[i]/10 % 10);
            v = v + temp;
        }
        
        if (originalnumber[12] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
    }
    
    // Checking for American Express (AMEX) - 15 digits, starts with 34 or 37.
    if (count == 15)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[14] == 3 && v % 10 == 0 && (originalnumber[13] == 4 || originalnumber[13] == 7))
      {
        printf("AMEX\n");
      }
      else
      {
        printf("INVALID\n");
      }
    }
    
    // Checking for Visa and MasterCard - 16 digits, starts with 51, 52, 53, 54, or 55
    if (count == 16)
    {
      for (int i = 0; i < count; i++)
      {
        temp = (number[i] % 10) + (number[i]/10 % 10);
        v = v + temp;
      }
      if (originalnumber[15] == 4 && v % 10 == 0)
      {
        printf("VISA\n");
      }
      else if (originalnumber[15] == 5 && v % 10 == 0 && (originalnumber[14] == 1 || originalnumber[14] == 2 || originalnumber[14] == 3 || originalnumber[14] == 4 || originalnumber[14] == 5))
        {
            printf("MASTERCARD\n");
        }
      else
      {
        printf("INVALID\n");
      }
    }
  
    return 0;
} 
