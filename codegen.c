#include "kx.h"

void emit_start() {
    printf("BITS 64\n");
    printf("org 0x100000\n");
    printf("_start:\n");
}
