#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);
char cipherchar(char plaintext, int shift);

int main(int argc, string argv[])
{
    // Check if exactly 1 command-line argument was input
    if (argc != 2)
    { 
        printf("Usage: ./vigenere keyword\n");
        return 0;
    } 
    string s = argv[1];
    
    int type;
    // Interate over every character and exit if char is not alphabetic
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        type = isalpha(s[i]);
        if (type == 0)
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    
    // Prompt user for secret message
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    int key;
    for (int i = 0, n = strlen(plaintext); i < n; i ++)
    {
        key = shift(argv[1][0]);
        ciphertext[i] = cipherchar(plaintext[i], key = shift(argv[1][0]));
    }
    
    printf("ciphertext: ");
    return 0;   
}

// Create function to convert character into shift value
int shift(char c)
{
    char c_lower = tolower(c);
    int shift = (c_lower - 'a') % 26;
    return shift;
}

char cipherchar(char plainchar, int key)
{
    char cipherchar;
    
    // Shift upper case letters
    if (plainchar >= 'A' && plainchar <= 'Z')
    {
        cipherchar = (plainchar + key - ('A')) % 26 + 'A';
        return cipherchar;     
    }
    // Shift lower case letters
    else if (plainchar >= 'a' && plainchar <= 'z')
    {
        cipherchar = (plainchar + key - ('a')) % 26 + 'a';
        return cipherchar;   
    }
    // If not alphabetic character, return plaintext
    else
    {
        return plainchar;
    }    
}
