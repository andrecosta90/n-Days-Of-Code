#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int START_INDEX = 65;

void initialize_array(int array[], int size);
int is_key_valid(string key);
void substitution(string plaintext, string key, char ciphertext[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    if (!is_key_valid(argv[1]))
    {
        printf("Invalid Key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    char ciphertext[200];

    substitution(plaintext, argv[1], ciphertext);
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int is_key_valid(string key)
{
    int count[26];
    initialize_array(count, 26);

    for (int i = 0; key[i] != '\0'; i++)
    {
        if (!isalpha(key[i]))
        {
            return 0;
        }
        else
        {
            char c = toupper(key[i]);
            int index = ((int) c) - START_INDEX;
            count[index]++;
            if (count[index] > 1)
            {
                return 0;
            }
        }
    }
    return 1;
}

void initialize_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void substitution(string plaintext, string key, string ciphertext)
{

    int i;
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        char temp = toupper(plaintext[i]);

        ciphertext[i] = temp;
        if (isalpha(temp))
        {
            int index = ((int) temp) - START_INDEX;

            char converted = key[index];
            if (islower(plaintext[i]))
            {
                converted = tolower(converted);
            }
            else
            {
                converted = toupper(converted);
            }
            ciphertext[i] = converted;
        }
    }
    ciphertext[i] = '\0';
}
