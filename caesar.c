#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // Check if exactly 1 command-line argument was input
    if (argc != 2)
    { 
        printf("Usage: ./caesar key\n");
        return 0;
    } 
    string s = argv[1];
        
    // Interate over each character in string s
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Terminate program if any character is not decimal digit
        if (s[i] < '0' || s[i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;   
        }   
    }
    
    // Coerce string to int and print
    int key = atoi(s);
    
    // Prompt user for secret message
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    // Shift all characters by key preserving case and special characters
    string ciphertext;
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Shift upper case letters
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", (plaintext[i] + key - ('A')) % 26 + 'A');
        }
        // Shift lower case letters
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", (plaintext[i] + key - ('a')) % 26 + 'a');
        }
        else
        {
            printf("%c", plaintext[i]);
        }    
    }
    printf("\n");
}
