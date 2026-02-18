#include "kx.h"

typedef enum {
    AST_NUM,
    AST_ADD,
    AST_ASSIGN,
    AST_VAR
} ASTType;

typedef struct AST {
    ASTType type;
    struct AST *left;
    struct AST *right;
    long value;
    char name[32];
} AST;
