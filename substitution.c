#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool validateKey(string key)
{

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return false;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return false;
            }
        }
    }

    return true;
}

char substitute(char c, string key)
{
    if (isupper(c))
    {
        int pos = c - 'A';
        return toupper(key[pos]);
    }
    else if (islower(c))
    {
        int pos = c - 'a';
        return tolower(key[pos]);
    }
    else
    {
        return c;
    }
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!validateKey(argv[1]))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        printf("%c", substitute(plaintext[i], argv[1]));
    }
    printf("\n");
}
