#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char  buff[7];
	int res;
	
	res = read(1, buff, strlen(buff));
	/*if(res != strlen(buff)) {
		perror("read failed");
	}*/
	res = write(1, buff, strlen(buff));
	if(res != strlen(buff)) {
		perror("write failed");
	}
	
	exit(0);
}
