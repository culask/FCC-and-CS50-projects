#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

string get_nextkey(string currentkey);
string get_nextkeyi(string currentkey, int index);
int get_nextchar(char current);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string hash = argv[1];
        char salt[3];
        salt[0] = hash[0];
        salt[1] = hash[1];
        salt[2] = '\0';
        //printf("%lu %s\n",strlen(salt),salt);
        char key[6];
        key[0] = 'A';
        key[1] = '\0';
        for (int i = 0; i < 380204032; i++)
        {
            //printf("testing key: %s\n",key);
            string keyhash = crypt(key, salt);
            if (strcmp(hash, keyhash) == 0)
            {
                printf("%s\n", key);
                return 0;
            }
            string akey = get_nextkey(key);
        }     
    }
    printf("Usage: ./crack hash\n");
    return 1;
}

string get_nextkey(string currentkey)
{
    int index = strlen(currentkey) - 1;
    return get_nextkeyi(currentkey, index);
}

string get_nextkeyi(string currentkey, int index)
{
    int length = strlen(currentkey);
    int nextchar = get_nextchar(currentkey[index]);
    if (nextchar != 0)
    {
        currentkey[index] = nextchar;
    }
    else if (index == 0)
    {
        for (int i = 0; i < length + 1; i++)
        {
            currentkey[i] = 'A';
        }
        currentkey[length + 1] = '\0';
    }
    else
    {
        currentkey[index] = 'A';
        index--;
        return get_nextkeyi(currentkey, index);
    }
    return currentkey;
}

int get_nextchar(char current)
{
    int nextchar = current + 1;
    if (nextchar < 123)
    {
        if (nextchar > 90 && nextchar < 97)
        {
            nextchar = 97;
        }
    }
    else
    {
        return 0;
    }
    return nextchar;
}
