#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_number(string key);
string encrypt_caesar(int key, string ptext);

int main(int argc, string argv[])
{
    //check if # of arguments are correct
    if (argc == 2)
    {
        string keystr = argv[1];
        //check if key is number
        if (is_number(keystr))
        {
            //convert key to int
            int key = atoi(keystr);
            //get user input
            string ptext = get_string("plaintext: ");
            //encrypt the input
            string ctext = encrypt_caesar(key, ptext);
            printf("ciphertext: %s\n", ctext);
            //close program(added to avoid typing usage again)
            return 0;
        }
    }
    printf("Usage: ./caesar key\n");
    return 1;
}

string encrypt_caesar(int key, string ptext)
{
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        if (islower(ptext[i]))
        {
            ptext[i] = ((ptext[i] - 'a' + key) % 26) + 'a'; 
        }
        else if (isupper(ptext[i]))
        {
            ptext[i] = ((ptext[i] - 'A' + key) % 26) + 'A'; 
        }
    }
    return ptext;
}

bool is_number(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
    }
    return true;
}
