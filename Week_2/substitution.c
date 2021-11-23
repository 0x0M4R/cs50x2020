#include<cs50.h>
#include<stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
    //Checking if 1 command-line argurment has been entered

    if (argc != 2)
    {
        printf("1 command-line argument not entered\n");
        return 1;
    }

    //Checking if 26 characters has been entered in key

    else if (strlen(argv[1]) != 26)
    {
        printf("invalid command-line arguement\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            //Checking if non-alphabetical characters has been entered in key

            if (argv[1][i] < 65 || argv[1][i] > 122)
            {
                printf("invalid command-line arguement\n");
                return 1;
            }

            //Checking if duplicate characters has been entered in key

            for (int j = (i + 1); j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("invalid command-line arguement\n");
                    return 1;
                }
            }
        }

        //Getting plaintext string from user

        int cipher[100];
        string plaintext = get_string("plaintext:");
        printf("ciphertext: ");

        //Converting plaintext into cipher and printing cipher

        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int a = plaintext[i];

            //for uppercase plaintext

            if (a >= 'A' && a <= 'Z')
            {
                if (argv[1][(a - 65)] >= 'A' && argv[1][a - 65] <= 'Z')
                {
                    int b = argv[1][a - 65];
                    cipher[i] = b;
                    printf("%c", cipher[i]);
                }
                else if (argv[1][a - 65] >= 'a' && argv[1][a - 65] <= 'z')
                {
                    int b = argv[1][a - 65];
                    cipher[i] = b - 32;
                    printf("%c", cipher[i]);
                }
            }

            //for lowercase plaintext

            else if (a >= 'a' && a <= 'z')
            {
                if (argv[1][(a - 97)] >= 'A' && argv[1][a - 97] <= 'Z')
                {
                    int b = argv[1][a - 97];
                    cipher[i] = b + 32;
                    printf("%c", cipher[i]);
                }
                else if (argv[1][a - 97] >= 'a' && argv[1][a - 97] <= 'z')
                {
                    int b = argv[1][a - 97];
                    cipher[i] = b;
                    printf("%c", cipher[i]);
                }
            }

            //printing plaintext character if it is not alphabetical character

            else
            {
                printf("%c", plaintext[i]);
            }
        }
        //print new line and exit
        printf("\n");
        return 0;
    }
}