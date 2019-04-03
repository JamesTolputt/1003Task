#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Make it so char* (C strings) can be written as a "string" variable
// eg) string mystring = "hello world";
typedef char* string; // Just cause i like c++ alright... don't judge

// Function Definitions AKA. saying "hey, compiler there are functions down under main that look like this go find them"
//// Encrypts string "input" using a rot cypher, which shifts the letters by "shift" in the alphabet
//// ~EXAMPLE~
//// ORIGINAL |  I AM AN EXAMPLE
//// ENCRYPTED|  K CO CP GZCORNG <- LETTERS MOVED TO PLACES FORWARD IN ALPHABET
string rotEncrypt(string input, int shift);
//// Encrypts string "input" using a substitution cypher, which swaps letters with the new "alphabet
string subEncrypt(string input, string alphabet);

int main(int argc, string argv[])
{
    string original = malloc(sizeof(char)*200);
    original[0] = 'A';
    original[1] = '\0';
    printf("Text %s was shifted %d to get %s.", original, 2, rotEncrypt(original, 2));

    return 0;
}

bool isLetter(char character)
{
    if ((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
        return true;
    else
        return false;
}

bool inRange(int value, int min, int max)
{
    if (value >= min && value <= max)
        return true;
    else
        return false;
}

bool isCapital(char character)
{
    if (character >= 'A' && character <= 'Z')
        return true;
    else
        return false;
}

bool isLowercase(char character)
{
    if (character >= 'a' && character <= 'z')
        return true;
    else
        return false;
}

char toCapital(char character)
{
    return character-32;
}

char toLowercase(char character)
{
    return character+32;
}

string rotEncrypt(string input, int shift)
{
    string sent = malloc(sizeof(char)*200);
    strcpy(sent, input);
    for (int i = 0; i < strlen(input); i++)
    {
        char original_char = sent[i];
        sent[i] -= isCapital(original_char)*65 +  // convert ASCII A=65,B=66,etc. to easier A=0,B=1,etc. if isCapital() is false it will return 0. 0*65 is 0 therefore ignored
                    isLowercase(original_char)*97; // convert ASCII a=97,B=98,etc. to easier a=0,b=1,etc.

        printf("Current character is: %d\n", (int)sent[i]);
        sent[i] = (sent[i] + shift) % 26;

        sent[i] += isCapital(original_char)*65 +   // convert back to ASCII
                    isLowercase(original_char)*97; // convert back to ASCII
    }

    return sent;
}

string subEncrypt(string input, string alphabet)
{
    for (int i = 0; i < strlen(input); i++)
    {
        if (isLetter(input[i]))
        {
            if (isCapital(input[i]))
                /* Say input[i] = 'A' and alphabet[0] = 'Z'
                 * 'A' = alphabet[ 'A' - 'A' ]
                 * first letter = alphabet [0 (first letter of new alphabet)]
                */
                input[i] = alphabet[input[i] - 'A'];
            else
                input[i] = alphabet[input[i] - 'A'];
        }
    }

    return input;
}
