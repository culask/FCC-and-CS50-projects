#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_valid(string key);
string encrypt_vigenere(string keyword, string ptext);
int shift(char c);

int main(int argc, string argv[])
{
    //check if # of arguments are correct
    if (argc == 2)
    {
        string keyword = argv[1];
        //check if key is alphabetic character array
        if (is_valid(keyword))
        {
            //get user input
            string ptext = get_string("plaintext: ");
            //encrypt the input
            string ctext = encrypt_vigenere(keyword, ptext);
            printf("ciphertext: %s\n", ctext);
            //close program(added to avoid typing usage again)
            return 0;
        }
    }
    printf("Usage: ./vigenere keyword\n");
    return 1;
}

int shift(char c)
{
    if (islower(c))
    {
        return c - 'a';
    }
    else
    {
        return c - 'A';
    }
}

string encrypt_vigenere(string key, string ptext)
{
    int keylen = strlen(key);
    int i_key = 0;
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        if (islower(ptext[i]))
        {
            ptext[i] = ((ptext[i] - 'a' + shift(key[i_key % keylen])) % 26) + 'a';
            i_key++;
        }
        else if (isupper(ptext[i]))
        {
            ptext[i] = ((ptext[i] - 'A' + shift(key[i_key % keylen])) % 26) + 'A';
            i_key++;
        }
    }
    return ptext;
}

bool is_valid(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
    }
    return true;
}
