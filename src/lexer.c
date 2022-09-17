#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>

lexer_o new_lexer(char *file_name, struct arguments *args)
{
    // Get file contents
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        printf("Could not open file %s\n", file_name);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char *file_contents = malloc(file_size + 1);
    fread(file_contents, file_size, 1, file);
    file_contents[file_size] = '\0';
    fclose(file);

    printf("%s\n", file_contents);
    int still_lexing = 1;
    int pos = 0;
    printf("|");

    long i = 0;
    while (still_lexing)
    {
        // The current character;
        char c = file_contents[i];

        // Visual component
        if (c != '\n')
        {
            pos++;
            if (pos == 1)
            {
                printf("\b\b\b/ %c", c);
            }
            if (pos == 2)
            {
                printf("\b\b\b- %c", c);
            }
            if (pos == 3)
            {
                printf("\b\b\b\\ %c", c);
            }
            if (pos == 4)
            {
                printf("\b\b\b| %c", c);
                pos = 0;
            }
        }

        if(c == "#") {
            token t;
            t.type = Bpt;
        }

        // Prep for next iteration.
        i++;

        // Check for end of file.
        if (i > file_size)
        {
            if(still_lexing == 1) {
                printf("\b\b\bThe lexer was unable to finish the lexical analysis before the EOF.\n");
                exit (1);
            }
        }
    }
};