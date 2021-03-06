#ifndef GLUE_H
#define GLUE_H
#include "ast.h"
#include "symbol_table.h"

#define printi(...) putchar('\t'); printf(__VA_ARGS__); putchar('\n');
#define printl(label) printf("L%ld:\n", label);
#define burm_invoke(root) /* printf("# burm_invoke\n"); node_print(root, 0); */ burm_label(root); burm_reduce(root, 1);

//reg_free_recursive(root->left); reg_free_recursive(root->right);

void funcdef(char *name, symbol_table *table);
char *gen_add(ast_node *bnode);
char *gen_sub(ast_node *bnode);
char *gen_mul(ast_node *bnode);
char *binary(char *op, ast_node *first, ast_node *second, bool commutative);
char *reg_new_var(void);
char *reg_new_par(void);
bool is_var(char *reg);
bool is_par(char *reg);
void reg_free(char *reg);
void reg_reset();
void reg_usage_print();

extern unsigned long label;

extern void burm_reduce(NODEPTR_TYPE bnode, int goalnt);
extern STATEPTR_TYPE burm_label(NODEPTR_TYPE p);
#endif
