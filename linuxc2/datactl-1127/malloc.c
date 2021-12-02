#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE (1024 * 10240)
#define PHY_MEM (10240 )

int main() {

	char * some_memory;
	int mem_give = 0;
	while(1) {
		if((some_memory = (char *)malloc(MAX_SIZE)) != NULL) {
			sprintf(some_memory, "HWLLOW WORD ILOVEU\n");
			printf("somedata===>%p, memgive===>%d, sizeofdata===>%d, strlendata====>%d\n", some_memory, mem_give, sizeof(some_memory), strlen(some_memory));
			mem_give++;
		} else exit(1);
	}
	// while(1) {
	// 	*some_memory = '\0';
	
	// 	printf("%p", some_memory);
	// 	some_memory++;
	// }
	 free(some_memory);
	exit(EXIT_SUCCESS);

}
