#include <stdlib.h>
#include <stdio.h>

int main() {
	printf("we would run ps process ..\n");
	system("ps -xua &");
	printf("done..\n");
	exit(0);
}
