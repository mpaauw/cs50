#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

long get_cc_number(void);
bool validate_checksum(long num);
void identify_provider(long num);

int main(int argc, string argv[])
{
    long cc_number = get_cc_number();
    if(validate_checksum(cc_number))
    {
        identify_provider(cc_number);
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_cc_number(void)
{
    long num;
    long check;
    int count = 0;
    do
    {
        num = get_long("Number: ");
        check = num;
        while(check > 0)
        {
            check /= 10;
            count++;
        }

        // TEST
        printf("LENGTH: %i", count);
        ////////////

    } while(count != 13 && count != 15 && count != 16);
    return num;
}

bool validate_checksum(long num)
{
    // count digits in cc number:
    int length = 0;
    int check = num;
    while(check > 0)
    {
        check /= 10;
        length++;
    }

    // TEST
    printf("CHECKSUM LENGTH: %i", length);
    ////////////
    
    // convert cc number to string for easy digit retrieval:
    char numString[length];
    sprintf(numString, "%lu", num);
    
    // conduct initial step of luhn's algorithm:
    int digits[sizeof(numString) / 2];
    int iter = 0;
    for(int i = sizeof(numString) - 2; i >= 0; i -= 2)
    {
        int digit = (int)numString[i] * 2;
        digits[iter++] = digit;        
    }
    int firstSum = 0;
    for(int i = 0; i < sizeof(digits); i++)
    {
        int digit = digits[i];
        int digitCheck = digit;
        int digitLength = 0;
        while(digitCheck > 0)
        {
            digitCheck /= 10;
            length++;
        }
        char digitString[digitLength];
        sprintf(digitString, "%i", digit);
        for(int j = 0; j < sizeof(digitString); j++)
        {
            firstSum += (int)digitString[j];
        }
    }
    
    // conduct secondary step of luhn's algorithm:
    int secondSum = 0;
    for(int i = sizeof(numString) - 1; i >= 0; i -= 2)
    {
        int digit = (int)numString[i];
        secondSum += digit; 
    }
    
    // conduct third and final step of luhn's algorithm:
    if((firstSum + secondSum) % 10 == 0)
    {
        return true;
    }
    return false;
}

void identify_provider(long num)
{
    int length = 0;
    long check = num;
    while(check > 0)
    {
        check /= 10;
        length++;
    }
    char numString[length];
    sprintf(numString, "%lu", num);
    
    char first = numString[0];
    char second = numString[1];
    
    // check amex:
    if(first == '3' && (second == '4' || second == '7'))
    {
        printf("AMEX\n");
    }
    // check mastercard:
    else if(first == '5' && (second == '1' || second == '2' || second == '3' || second == '4' || second == '5'))
    {
        printf("MASTERCARD\n");
    }
    // check visa:
    else if(first == '4')
    {
        printf("VISA\n");
    }
    // invalid:
    else
    {
        printf("INVALID\n");    
    }
}
