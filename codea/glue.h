#ifndef GLUE_H
#define GLUE_H
#include "ast.h"
#include "symbol_table.h"

#define printi(...) putchar('\t'); printf(__VA_ARGS__); putchar('\n');
#define reg_reset() memset(var_usage, 0, sizeof(int) * 9); memset(par_usage, 0, sizeof(int) * 6);

void funcdef(char *name, symbol_table *table, ast_node *node);
char *binary(char *op, char *first, char *second, bool commutative);
char *reg_new_var(void);
char *reg_new_par(void);
bool is_var(char *reg);
bool is_par(char *reg);
void reg_free(char *reg);
void reg_reset_all();

#endif
