#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>



int main() {
	char c[1024];
	int res, in, out;

	in = open("src", O_RDONLY);
	out = open("dst", O_WRONLY|O_CREAT);

	while(read(in, c, 1023) > 0 ) {
		res = write(out, c, strlen(c));
	}

	exit(0);
}
