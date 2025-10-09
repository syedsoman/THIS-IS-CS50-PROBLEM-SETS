#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");
    long temp = num;
    int sum = 0, count = 0;

    // Luhn’s Algorithm
    while (temp > 0)
    {
        int digit = temp % 10;

        if (count % 2 == 1)
        {
            int dbl = digit * 2;
            sum += (dbl / 10) + (dbl % 10);
        }
        else
        {
            sum += digit;
        }

        temp /= 10;
        count++;
    }

    // Check validity
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // Extract first two digits
    long check = num;
    while (check >= 100)
    {
        check /= 10;
    }
    int first2 = check;

    // Decide card type
    if ((first2 == 34 || first2 == 37) && count == 15)
    {
        printf("AMEX\n");
    }
    else if (first2 >= 51 && first2 <= 55 && count == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((first2 / 10 == 4) && (count == 13 || count == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
