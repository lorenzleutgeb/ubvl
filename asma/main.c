#include <stdlib.h>

extern int asma(char*);

/*int asma(char *s) {
	int c = 0, i;
	for (i = 0; i < 16; i++)
		if (s[i] == ' ')
			c++;
	return c;
}*/

int main(int argc, char** argv) {
	exit(asma("    "));
}
