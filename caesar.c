#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // commandline arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argv[1] == NULL)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string CLA = argv[1];
    int sizeCLA = strlen(CLA);
    bool digitcheck = false;
    int key;
    for (int i = 0; i < sizeCLA; i++)
    {
        if (CLA[i] >= 48 && CLA[i] <= 57)
        {
            digitcheck = true;
        }
        else
        {
            digitcheck = false;
            printf("Usage: ./caesar key\n");
            return 1;
            break;
        }
    }
    // conversion of key from string to integer
    if (digitcheck == true)
    {
        key = atoi(CLA);
    }

    //prompt for plaintext input
    string plaintext = get_string("plaintext: ");
    int plainLength = strlen(plaintext);

    //encryption
    for (int i = 0; i < plainLength; i++)
    {
        if (islower(plaintext[i]))
        {
            plaintext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
    }
    //cipher text
    printf("ciphertext: %s\n", plaintext);

}