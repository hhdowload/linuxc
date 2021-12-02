#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
	char ch;
	while((ch = getchar()) != EOF) {
		putchar(toupper(ch));
	} 
	
	exit(0);
}


