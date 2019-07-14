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
        return 1;
    } 
    
    // Save key in string s 
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
    int key_position = 0;
    int key_length = strlen(s);
    int shift_value;
    // Interate over each char in plain text and encode it as ciphertext
    for (int i = 0, n = strlen(plaintext); i < n; i ++)
    {
        // Calculate shift value given by specific key position
        shift_value = shift(s[key_position % key_length]);
    
        // Shift upper case letters 
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = (plaintext[i] + shift_value - ('A')) % 26 + 'A';
            // Increment key position
            key_position++;
               
        }
        // Shift lower case letters
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = (plaintext[i] + shift_value - ('a')) % 26 + 'a';
            // Increment key position 
            key_position++;
        }
        // If not alphabetic character, return plaintext
        else
        {
            // Do not encode non-alphabetic characters, do not increment key position
            ciphertext[i] = plaintext[i];
        }    
    }
    
    // print ciphertext
    printf("ciphertext: %s\n", ciphertext);
    return 0;   
}

// Create function to convert character into shift value
int shift(char c)
{
    char c_lower = tolower(c);
    int shift = (c_lower - 'a') % 26;
    return shift;
}
