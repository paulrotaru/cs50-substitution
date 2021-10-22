#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main(int argc, string argv[])
{

    // check argv to take only the key
    if (argc != 2)
    {
        printf("No key found!\n");
        return 1;
    }
    int keylenght = strlen(argv[1]);

    //check to be only letters in the key
    for (int i = 0; i < keylenght; i++)
    {
       if (isalpha(argv[1][i]) == 0)
       {
           printf("The key must contain only letters!\n");
           return 1;
       }
    }
    //check the key to contain 26 chars
    if (keylenght != 26)
    {
       printf("Key must contain 26 characters!\n");
       return 1;
    }
   //check the key to don't have duplicate letters
    for (int i = 0; i < keylenght; i++)
    {
        for (int j = 0; j < keylenght; j++)
        {
           if (i != j)
           {
                if (toupper(argv[1][i]) == toupper(argv[1][j]))
                {
                    printf("The key must contain unique characters!\n");
                    return 1;
                }
           }
        }
    }
    // ask for plaintext
    string plaintext = get_string("plaintext: ");

    int textlength = strlen(plaintext);

    int factor; //to store the chars position in the key

    printf("ciphertext: ");

    for (int i = 0; i < textlength; i++)
    {
        // check every char of plaintext to be alpha
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                //switch the char in the plaintext with char from the factor position in the key
                factor = plaintext[i] % 65;
                plaintext[i] = toupper(argv[1][factor]);

            }
            else if (islower(plaintext[i]))
            {
                //switch the char in the plaintext with char from the factor position in the key
                factor = plaintext[i] % 97;
                plaintext[i] = tolower(argv[1][factor]);

            }
        }


        printf("%c", plaintext[i]);

    }

    printf("\n");

}