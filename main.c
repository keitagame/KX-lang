#include "kx.h"

extern void parse_entry();
extern void emit_start();

int main(int argc, char **argv) {
    FILE *f = fopen(argv[1], "r");

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    rewind(f);

    char *src = malloc(size + 1);
    fread(src, 1, size, f);
    src[size] = 0;

    init_lexer(src);

    emit_start();
    parse_entry();

    return 0;
}
