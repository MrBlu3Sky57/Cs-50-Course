#include <stdio.h>
#include <math.h>

void is_valid(long number);

int main(void)
{
    // Get number
    long number;
    printf("Number: ");
    scanf("%li", &number);

    // Check validity
    is_valid(number);
}

void is_valid(long number)
{

    // Only use log function if number is greater than 0
    if (number > 0)
    {
        int num_digits = floor(log10(number)) + 1;
        long remainder = 0;
        int digit;
        int sum = 0;


        // Go through each individual digit
        for (int i = num_digits - 1; i > -1; i--)
        {
            // Get digit
            digit = number / pow(10, i) - remainder;
            remainder = (remainder + digit) * 10;

            // If digit is even multiply it by two and add the product's digits to the sum
            if (i % 2 != 0)
            {
                int new_digit = digit * 2;
                int product_remainder = new_digit - floor(new_digit / 10) * 10;
                sum = sum + product_remainder + new_digit / 10;
            }

            // Else just add digit to the sum
            else
            {
                sum = sum + digit;
            }
        }


        // If card is valid find card type
        if (sum % 10 == 0)
        {
            if (floor(number / pow(10, num_digits - 1)) == 4 && (num_digits == 13 || num_digits == 16))
            {
                printf("VISA\n");
            }

            else if ((floor(number / pow(10, num_digits - 2)) == 34 || floor(number / pow(10, num_digits - 2)) == 37) && num_digits == 15)
            {
                printf("AMEX\n");
            }

            else if (floor(number / pow(10, num_digits - 2)) > 50 && floor(number / pow(10, num_digits - 2)) < 56 && num_digits == 16)
            {
                printf("MASTERCARD\n");
            }

            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }

}