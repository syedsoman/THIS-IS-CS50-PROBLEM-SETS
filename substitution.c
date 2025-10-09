#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function prototypes
bool check_key(string k);
char encrypt_char(char ch, string key);

int main(int argc, string argv[])
{
    // Ensure one argument (the key)
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    string key = argv[1];

    // Validate key
    if (!check_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Prompt user for plaintext
    string text = get_string("plaintext: ");

    printf("ciphertext: ");

    // Encrypt character by character
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c", encrypt_char(text[i], key));
    }
    printf("\n");
    return 0;
}

// Validate substitution key
bool check_key(string k)
{
    // Must be length 26
    if (strlen(k) != 26)
    {
        return false;
    }

    // Track used letters
    bool used[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(k[i]))
        {
            return false; // Non-alphabetic
        }

        int idx = toupper(k[i]) - 'A';
        if (used[idx])
        {
            return false; // Duplicate
        }
        used[idx] = true;
    }
    return true;
}

// Encrypt a single character
char encrypt_char(char ch, string key)
{
    if (isupper(ch))
    {
        int pos = ch - 'A';
        return toupper(key[pos]);
    }
    else if (islower(ch))
    {
        int pos = ch - 'a';
        return tolower(key[pos]);
    }
    else
    {
        return ch; // Non-letters unchanged
    }
}
