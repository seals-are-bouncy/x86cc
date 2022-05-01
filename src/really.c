#include "really.h"

#include <stdio.h>
#include "lexer.h"

void do_files(struct arguments *args) {
    for (size_t i = 0; i < args->file_count; i++)
    {
        printf("%s\n", args->files[i]);
        lexer_o l;
        l = new_lexer(args->files[i], args);
    }
};