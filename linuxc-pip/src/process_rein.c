#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int  argc, char * argv[]) {
	
	if(argc != 2) {
		 printf("error,please input again ex: script pathname");
		 exit(1);	
	}

/*	char  * in = "in";   */
	
	if(!freopen(argv[1], "r", stdin)) {
		fprintf(stderr,"wehava errot\n");
		exit(2);
	}
	execl("./processupper", "processupper", NULL);
	
	exit(0);
}


