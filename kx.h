#ifndef KX_H
#define KX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TOK_EOF,
    TOK_ID,
    TOK_NUM,
    TOK_ENTRY,
    TOK_FN,
    TOK_RETURN,
    TOK_ASM,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_SEMI,
    TOK_ASSIGN,
    TOK_PLUS
} TokenType;

typedef struct {
    TokenType type;
    char text[64];
    long value;
} Token;

extern Token current;

void next_token();
void init_lexer(const char *src);

#endif
