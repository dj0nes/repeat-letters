#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCII_LETTER_A 65
#define ASCII_LETTER_Z 90

int main(int argc, char* argv[]) {

    if( argv[1] == NULL ) {
        fprintf(stderr, "No filename given. Please supply a filename as the first and only argument.\n");
        return 1;
    }

    char* fName = argv[1];
    char* sample;
    FILE* text = fopen(fName,"r");

    if(text) {
        // determine length of file and allocate memory for its contents
        fseek(text,0,SEEK_END);
        long filesize = ftell(text);
        fseek(text,0,SEEK_SET);
        sample = calloc(filesize+2, sizeof(char)); // +2 to insert null terminator \0
        fread(sample,sizeof(char), filesize, text);
        sample[filesize] = '0';
        fclose(text);
    }
    else {
        fprintf(stderr, "Cannot open given file. Exiting.");
        return 1;
    }

    if(sample) {
        char* token;
        char* remainder = sample;

        int highest_letter_count = 0;
        int letter_count[26] = {0}; // size of ASCII shoutycase English alphabet, initialize to zero
        char max_letters[100] = {0};  // arbitrary size big enough for most words, initialize to zero
        char current_token[100]; // placeholder for unmangled token

        // tokenize input using whitespace as the delimeter
        while( (token = strtok_r(remainder, " ", &remainder)) ) {
            sprintf(current_token, "%s", token); // copy current token to holder before manipulation

            // count letters within the token, using ASCII codepoint as integer index in letter_count array
            for( int i = 0; token[i]; i++) {
                // case does not matter, so transform all letters to uppercase for simpler accounting
                int c = (char)toupper(token[i]);

                if( c < ASCII_LETTER_A || c > ASCII_LETTER_Z) {
                    // ignore it, it isn't a letter in A-Z
                }
                else {
                    letter_count[ c - ASCII_LETTER_A] += 1; // account for ascii offset, then mark the letter as counted
                }
            }

            // check if the token we just processed has more repeat letters than the previous max_letters word
            for( int i = 0; i < sizeof(letter_count)/sizeof(int); i++) {
                // the strictly greater than here ensures that in the event of a tie, the first word in the sample wins
                if(letter_count[i] > highest_letter_count) {
                    // then this word has more repeats than any other word
                    sprintf(max_letters, "%s", current_token); // copy the original token to the winner's place
                    highest_letter_count = letter_count[i]; // update highest letter count
                }
            }

            // now we are done with this token, so re-zero the per-token letter tally
            memset(letter_count, 0, sizeof(letter_count));
        }

        // the output!
        printf("%s\n", max_letters);

        // Memory cleanup
        free(sample);
    }
}
