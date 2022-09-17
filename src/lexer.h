#if !defined(_H_LEXER)
#define _H_LEXER

#include "arguments.h"

enum token_types {
    Statement, // Statement
    
    IntL, // Integer literal
    Strl, // String literal ""
    ChrL, // Character literal ''

    AddO, // Addition Operand + 
    SubO, // Subtraction Operand - 
    MulO, // Multiplication Operand *
    DivO, // Division Operand /
    
    EqE, // Equality Expression ==
    NeqE, // Inequality Expression !=
    LteE, // Less than or equal to Expression <=
    GteE, // Greater than or equal to Expression >=
    LtE, // Less than Expression <
    GtE, // Greater than Expression >

    AssOp, // Assignment Operator =
    IncOp, // Increment Operator ++
    DecOp, // Decrement Operator --
    AddOp, // Addition Operator +=
    SubOp, // Subtraction Operator -=
    MulOp, // Multiplication Operator *=
    DivOp, // Division Operator /=

    LprO, // Left Parenthesis (
    RprO, // Right Parenthesis )
    LbrO, // Left Bracket [
    RbrO, // Right Bracket ]
    LckO, // Left Curly Brace {
    RckO, // Right Curly Brace }

    EOFi, // End of File
    EOLi, // End of Line

    Bpt, // Begin preprocessor tag
    Pdt, // Preprocessor Define tag

    Prg, // Pragma

};

typedef struct _token token;
struct _token {
    enum token_types type;
    char *value;
};

typedef struct _lexer_o lexer_o;
struct _lexer_o {
    token **tokens;
    int count_tokens;
}; // Lexer object

lexer_o new_lexer(char *file_name, struct arguments *args);

#endif // _H_LEXER