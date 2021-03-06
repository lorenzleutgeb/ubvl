#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include <stdbool.h>

typedef int symbol_dimensions;

struct symbol_table {
	struct symbol_table *next;
	char *id;
	symbol_dimensions dimensions;
	int reg;
};

typedef struct symbol_table symbol_table;

symbol_table *symbol_table_clone(symbol_table *table);
symbol_table *symbol_table_get(symbol_table *table, char *id);
symbol_table *symbol_table_merge(symbol_table *a, symbol_table *b, bool check);
symbol_table *symbol_table_add(symbol_table *table, char *id, symbol_dimensions dimensions, bool check);
symbol_table *symbol_table_add_var(symbol_table *table, char *id, symbol_dimensions dimensions, bool check);
symbol_table *symbol_table_add_par(symbol_table *table, char *id, symbol_dimensions dimensions, bool check);
symbol_table *symbol_table_add_with_reg(symbol_table *table, char *id, symbol_dimensions dimensions, bool check, char reg);
symbol_dimensions symbol_table_get_dimensions(symbol_table *table, char* id);

void symbol_table_print(symbol_table *table);
void symbol_table_print_descriptive(symbol_table *table, char* description);

void same_dimensions(symbol_dimensions a, symbol_dimensions b);
void is_array(symbol_dimensions dimensions);
void is_integer(symbol_dimensions dimensions);
void variable_exists(symbol_table *table, char *id);

#endif
