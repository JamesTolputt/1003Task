// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <stdlib.h>

// #include <ctype.h>

// #define MAX_WORD_SIZE 46 // Assumes words aren't longer than the longest word found in major dictionaries (Pneumonoultramicroscopicsilicovolcanoconiosis) 45+1 +1 due to terminating null character
// typedef char word[MAX_WORD_SIZE];
// typedef struct
// {
// 	int wordcount;
// 	int* wordlengths;
// 	word* words;
// } WordList;

// // Function Definitions AKA. saying "hey, compiler there are functions down under main that look like this go find them"
// //// Encrypts string "input" using a rot cypher, which shifts the letters by "shift" in the alphabet
// //// ~EXAMPLE~
// //// ORIGINAL |  I AM AN EXAMPLE
// //// ENCRYPTED|  K CO CP GZCORNG <- LETTERS MOVED TO PLACES FORWARD IN ALPHABET
// char* rotEncrypt(char* input, int shift);
// char* rotDecrypr(char* input);
// WordList loadDictionary();

// int main(int argc, char* argv[])
// {
// 	WordList dictionary = loadDictionary();
    
// 	char original[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA "
// 		"SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM "
// 		"AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL "
// 		"NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA "
// 		"VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ "
// 		"VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";

//     //printf("Text %s was shifted %d to get %s.\n", original, 19, rotEncrypt(original, 19));
// 	for (int i = 0; i < dictionary.wordcount; i++)
// 	{	
// 		printf("%s\n\r", dictionary.words[i]);
// 		fflush( stdout );
// 	}
// 	puts( rotEncrypt(original, 19) );
	
// 	getchar();
	
//     return 0;
// }

// bool inRange(int value, int min, int max)
// {
//     if (value >= min && value <= max)
//         return true;
//     else
//         return false;
// }

// char toCapital(char character)
// {
//     return character-32;
// }

// char toLowercase(char character)
// {
//     return character+32;
// }

//}

// char* rotDecrypt(char* input)
// {
// 	char temp[strlen(input)+1];
// 	strcpy(temp, input);
	
// 	for (int i = 0; i < 26; i++)
// 	{
// 		rotEncrypt(temp, i);
		
// 	}
// }

// WordList loadDictionary()
// {
// 	WordList list;
// 	list.words = malloc( 1 * sizeof( word ) ); // Allocate memory for 1 word of size MAX_WORD_SIZE(46) letters
// 	list.wordlengths = malloc( 1 * sizeof( int ) );
// 	FILE * dictionary = fopen("dictionary.txt", "r");
	
// 	int i = 0;
// 	for(;;)
// 	{
// 		word currentWord; 
// 		if (fgets(currentWord, MAX_WORD_SIZE, dictionary) == NULL)
// 			break;
		
// 		for (int j = strlen(currentWord)+1; j != 0; j--)
// 		{
// 			if (currentWord[j] == '\r' || currentWord[j] == '\n')
// 			{
// 				currentWord[j] = '\0';
// 			}
// 		}
		
// 		for (int k = 0; k < strlen(currentWord); k++)
// 			printf("|%c|", currentWord[k]);
		
// 		realloc( list.words, sizeof(list.words) + ( i * sizeof(word) ) );
// 		realloc( list.wordlengths, sizeof(list.wordlengths) + ( i * sizeof(int) ) );
		
// 		strcpy(list.words[i], currentWord);
// 		list.wordlengths[i] = strlen(currentWord);
		
// 		i++;
// 	}
	
// 	list.wordcount = i;
	
// 	return list;
// }

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modulas( int a, int b );
void rotEncrypt(char* input, int shift);
void rotDecrypt( char* input );
void toUpper( char* input );
int isNumber( char* input );
void removeTrail( char* input );

int main( int argc, char** argv )
{
	char decryptstring[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB";
	char encryptstring[] = "ATTACK AT SUNRISE";

	rotEncrypt( encryptstring, -1 );
	rotDecrypt( decryptstring );
	printf( "%s\n", encryptstring );

	return 0;
}

int modulas( int a, int b )
{
	int out = a % b;

	if ( out < 0 )
		out = b + out;

	return out;
}

void rotEncrypt( char* input, int shift )
{
    char temp[ strlen( input )+1 ];	 // A temporary string to do work on without changing the original string, +1 cause strlen does not include the terminating null character
    strcpy( temp, input ); 		     // Copy input string into the temporary string
	
    for ( int i = 0; i < strlen(input)+1; i++ )
    {
        char original_char = temp[i];
        temp[i] -= isupper( original_char ) * 65 +   // convert ASCII A=65,B=66,etc. to easier A=0,B=1,etc. if isupper() is false it will return 0. 0*65 is 0 therefore ignored
                    islower( original_char ) * 97;   // convert ASCII a=97,B=98,etc. to easier a=0,b=1,etc. if islower() is false it will return 0. 0*65 is 0 therefore ignored
                    						    	 // Note if another character (e.g. '\0') it will be ignored

		if ( isalpha( original_char ) )
			temp[i] = modulas( ( temp[i] + shift ), 26 );

        temp[i] += isupper( original_char ) * 65 +   // convert back to ASCII. For uppercase same as above conversion only backwards
                    islower( original_char ) * 97; 	 // convert back to ASCII. ^ only lowercase
    }

    strcpy( input, temp );
}

void rotDecrypt( char* input )
{
	toUpper( input );
	char temp[ strlen( input )+1 ];
	strcpy( temp, input );

	FILE *dictionary;

	int shift;
		char* token;
		token = strtok( temp, ",. -*:;|/" );

	while ( token != NULL )
	{
		for ( shift = 0; shift < 26; shift++ )
		{
			rotEncrypt( token, shift );

			dictionary = fopen ( "dictionary.txt", "r" );

			if ( dictionary != NULL )
			{
				char line [ 46 ];	// Size of the biggest word +1 cause null character

		  		while ( fgets ( line, sizeof( line ), dictionary ) != NULL ) // Read through dictionary line by line (and therefore word by word) and store in line
		  		{
		  			toUpper( line );
		  			removeTrail( line );
		     		if ( strcmp( line, token ) == 0) // the token (the decrypted word of the input string) and the line (a word from the dictionary) matches we have found our shift
		     		{
		     			printf("Hey we be done!\n");
		     			rotEncrypt( input, shift );
		     			fclose( dictionary );
		     			return;
		     		}
		  		}

		  		fclose( dictionary );
			}
			else
			  perror ( "dictionary could not be opened!" ); // Send error message

			rotEncrypt( token, -shift );
		}
		printf( "Attempted to decryption failed on token \"%s\".\n", token );
		token = strtok( NULL, ",. -*:;|/" );
	}
}

void toUpper( char* input )
{
	for (int i = 0; i <= strlen( input ); i++ )
	{
		if ( isalpha( input[i] ) )
			input[i] = toupper( input[i] );
	}
}

void removeTrail( char* input )
{
	char* position = strchr( input, '\n' );
	if ( position != NULL )
    	*position = '\0';

	position = strchr( input, '\r' );
	if ( position != NULL )
    	*position = '\0';
}

int isNumber( char* input )
{
	for ( int i = 0; i < strlen( input ); i++ )
	{
		if ( isdigit( input[i] ) ) {}
		else if ( input[i] == '-' ) {}
		else
			return -1;
	}
	return 1;
}