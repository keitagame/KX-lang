#include "kx.h"

static const char *src;
Token current;

void init_lexer(const char *s) {
    src = s;
    next_token();
}

static void skip_ws() {
    while (isspace(*src)) src++;
}

void next_token() {
    skip_ws();

    if (*src == 0) {
        current.type = TOK_EOF;
        return;
    }

    if (isalpha(*src)) {
        int i = 0;
        while (isalnum(*src)) {
            current.text[i++] = *src++;
        }
        current.text[i] = 0;

        if (!strcmp(current.text, "entry"))
            current.type = TOK_ENTRY;
        else if (!strcmp(current.text, "fn"))
            current.type = TOK_FN;
        else if (!strcmp(current.text, "return"))
            current.type = TOK_RETURN;
        else if (!strcmp(current.text, "asm"))
            current.type = TOK_ASM;
        else
            current.type = TOK_ID;

        return;
    }

    if (isdigit(*src)) {
        current.value = strtol(src, (char**)&src, 0);
        current.type = TOK_NUM;
        return;
    }

    switch (*src++) {
        case '{': current.type = TOK_LBRACE; return;
        case '}': current.type = TOK_RBRACE; return;
        case '(': current.type = TOK_LPAREN; return;
        case ')': current.type = TOK_RPAREN; return;
        case ';': current.type = TOK_SEMI; return;
        case '=': current.type = TOK_ASSIGN; return;
        case '+': current.type = TOK_PLUS; return;
    }

    printf("Unknown char\n");
    exit(1);
}
