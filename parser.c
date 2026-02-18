#include "kx.h"

void expect(TokenType t) {
    if (current.type != t) {
        printf("Parse error\n");
        exit(1);
    }
    next_token();
}

void parse_entry() {
    expect(TOK_ENTRY);
    expect(TOK_LBRACE);

    while (current.type != TOK_RBRACE) {
        next_token();
    }

    expect(TOK_RBRACE);
}
