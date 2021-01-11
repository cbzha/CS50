#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];
    int keysize = strlen(argv[1]);

    if (keysize != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < keysize; i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Key must only contain aphabetic characters.\n");
            return 1;
        }
    }
    for (int i = 0; i < keysize - 1; i++)
    {
        for (int j = i + 1; j < keysize; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    string plain = get_string("Plaintext: ");
    int size = strlen(plain);

    char plaintext[size];

    for (int i = 0; i < size; i++)
    {
        plaintext[i] = plain[i];
    }



    for (int i = 0; i < size; i++)
    {
        if (plaintext[i] == 'a')
        {
            plaintext[i] = tolower(key[0]);
        }
        else if (plaintext[i] == 'b')
        {
            plaintext[i] = tolower(key[1]);
        }
        else if (plaintext[i] == 'c')
        {
            plaintext[i] = tolower(key[2]);
        }
        else if (plaintext[i] == 'd')
        {
            plaintext[i] = tolower(key[3]);
        }
        else if (plaintext[i] == 'e')
        {
            plaintext[i] = tolower(key[4]);
        }
        else if (plaintext[i] == 'f')
        {
            plaintext[i] = tolower(key[5]);
        }
        else if (plaintext[i] == 'g')
        {
            plaintext[i] = tolower(key[6]);
        }
        else if (plaintext[i] == 'h')
        {
            plaintext[i] = tolower(key[7]);
        }
        else if (plaintext[i] == 'i')
        {
            plaintext[i] = tolower(key[8]);
        }
        else if (plaintext[i] == 'j')
        {
            plaintext[i] = tolower(key[9]);
        }
        else if (plaintext[i] == 'k')
        {
            plaintext[i] = tolower(key[10]);
        }
        else if (plaintext[i] == 'l')
        {
            plaintext[i] = tolower(key[11]);
        }
        else if (plaintext[i] == 'm')
        {
            plaintext[i] = tolower(key[12]);
        }
        else if (plaintext[i] == 'n')
        {
            plaintext[i] = tolower(key[13]);
        }
        else if (plaintext[i] == 'o')
        {
            plaintext[i] = tolower(key[14]);
        }
        else if (plaintext[i] == 'p')
        {
            plaintext[i] = tolower(key[15]);
        }
        else if (plaintext[i] == 'q')
        {
            plaintext[i] = tolower(key[16]);
        }
        else if (plaintext[i] == 'r')
        {
            plaintext[i] = tolower(key[17]);
        }
        else if (plaintext[i] == 's')
        {
            plaintext[i] = tolower(key[18]);
        }
        else if (plaintext[i] == 't')
        {
            plaintext[i] = tolower(key[19]);
        }
        else if (plaintext[i] == 'u')
        {
            plaintext[i] = tolower(key[20]);
        }
        else if (plaintext[i] == 'v')
        {
            plaintext[i] = tolower(key[21]);
        }
        else if (plaintext[i] == 'w')
        {
            plaintext[i] = tolower(key[22]);
        }
        else if (plaintext[i] == 'x')
        {
            plaintext[i] = tolower(key[23]);
        }
        else if (plaintext[i] == 'y')
        {
            plaintext[i] = tolower(key[24]);
        }
        else if (plaintext[i] == 'z')
        {
            plaintext[i] = tolower(key[25]);
        }
        else if (plaintext[i] == 'A')
        {
            plaintext[i] = toupper(key[0]);
        }
        else if (plaintext[i] == 'B')
        {
            plaintext[i] = toupper(key[1]);
        }
        else if (plaintext[i] == 'C')
        {
            plaintext[i] = toupper(key[2]);
        }
        else if (plaintext[i] == 'D')
        {
            plaintext[i] = toupper(key[3]);
        }
        else if (plaintext[i] == 'E')
        {
            plaintext[i] = toupper(key[4]);
        }
        else if (plaintext[i] == 'F')
        {
            plaintext[i] = toupper(key[5]);
        }
        else if (plaintext[i] == 'G')
        {
            plaintext[i] = toupper(key[6]);
        }
        else if (plaintext[i] == 'H')
        {
            plaintext[i] = toupper(key[7]);
        }
        else if (plaintext[i] == 'I')
        {
            plaintext[i] = toupper(key[8]);
        }
        else if (plaintext[i] == 'J')
        {
            plaintext[i] = toupper(key[9]);
        }
        else if (plaintext[i] == 'K')
        {
            plaintext[i] = toupper(key[10]);
        }
        else if (plaintext[i] == 'L')
        {
            plaintext[i] = toupper(key[11]);
        }
        else if (plaintext[i] == 'M')
        {
            plaintext[i] = toupper(key[12]);
        }
        else if (plaintext[i] == 'N')
        {
            plaintext[i] = toupper(key[13]);
        }
        else if (plaintext[i] == 'O')
        {
            plaintext[i] = toupper(key[14]);
        }
        else if (plaintext[i] == 'P')
        {
            plaintext[i] = toupper(key[15]);
        }
        else if (plaintext[i] == 'Q')
        {
            plaintext[i] = toupper(key[16]);
        }
        else if (plaintext[i] == 'R')
        {
            plaintext[i] = toupper(key[17]);
        }
        else if (plaintext[i] == 'S')
        {
            plaintext[i] = toupper(key[18]);
        }
        else if (plaintext[i] == 'T')
        {
            plaintext[i] = toupper(key[19]);
        }
        else if (plaintext[i] == 'U')
        {
            plaintext[i] = toupper(key[20]);
        }
        else if (plaintext[i] == 'V')
        {
            plaintext[i] = toupper(key[21]);
        }
        else if (plaintext[i] == 'W')
        {
            plaintext[i] = toupper(key[22]);
        }
        else if (plaintext[i] == 'X')
        {
            plaintext[i] = toupper(key[23]);
        }
        else if (plaintext[i] == 'Y')
        {
            plaintext[i] = toupper(key[24]);
        }
        else if (plaintext[i] == 'Z')
        {
            plaintext[i] = toupper(key[25]);
        }
    }

    printf("ciphertext: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c", plaintext[i]);
    }
    printf("\n");
}



