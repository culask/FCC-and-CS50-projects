#include <stdio.h>
#include <cs50.h>
#include <math.h>

int find_digit_num(long num);
int get_first_two_digits(long num);
bool checksum_luhn(long num);
bool check_mastercard(int ftd, int digits);
bool check_visa(int ftd, int digits);
bool check_amex(int ftd, int digits);

int main(void)
{
    long cc_num = get_long("Number: ");
    int digits = find_digit_num(cc_num);
    if (!(digits > 16 || digits < 13 || digits == 14))
    {
        if (checksum_luhn(cc_num))
        {
            //ftd for short of first 2 digits
            int ftd = get_first_two_digits(cc_num);
            if (check_mastercard(ftd, digits) || check_visa(ftd, digits) || check_amex(ftd, digits))
            {
                return 0;
            }        
        }
    }
    printf("INVALID\n");
}

bool check_amex(int ftd, int digits)
{
    if (digits == 15)
    {
        if (ftd == 34 || ftd == 37)
        {
            printf("AMEX\n");
            return true;
        }
    }
    return false;
}

bool check_mastercard(int ftd, int digits)
{
    if (digits == 16)
    {
        if (ftd >= 51 && ftd <= 55)
        {
            printf("MASTERCARD\n");
            return true;
        }
    }
    return false;
}

bool check_visa(int ftd, int digits)
{
    if (digits == 13 || digits == 16)
    {
        if (ftd / 10 == 4)
        {
            printf("VISA\n");
            return true;
        }
    }
    return false;
}

bool checksum_luhn(long num)
{
    int digits = find_digit_num(num);
    int sum_double = 0;
    int sum_single = 0;
    int digit;
    for (int i = 0; i < digits; i++)
    {
        if (i % 2 == 0)
        {
            sum_single += num % 10;
        }
        else
        {
            int addition = 2 * (num % 10);
            if (addition > 9)
            {
                int big_addition = (addition % 10) + (addition / 10);
                sum_double += big_addition;
            }
            else
            {
                sum_double += addition;
            }
        }
        num = num / 10;
    }
    return (sum_single + sum_double) % 10 == 0;
}

int find_digit_num(long num)
{
    return (int) log10(num) + 1;
}

int get_first_two_digits(long num)
{
    int digits = find_digit_num(num);
    long divider = pow(10, digits - 2);
    return num / divider;
}
