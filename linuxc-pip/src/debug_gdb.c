#include <stdlib.h>
#include <stdio.h>

char data[4096];
typedef struct {
    char *data;
    int key;
} item;

item array[] = {
    {"kill", 3},
    {"lion", 4},
    {"alin", 5},
    {"amazon", 2},
    {"alibaba", 1},
};

sort(a,n)
item *a;
{
    int i = 0, j = 0;
    int s = 1;

    for(; i < n && s != 0; i++ ) {
        s = 0;
        for(j = 0; j < n; j++) {
            if(a[j].key > a[j+1].key) {
                item t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
                s++;
            }
        }

        n--;
    }
}


int  main() {
    	int i = 0;
	sort(array,5);
 	#ifdef DEBUG
		for(;i < 5; i++) {
			printf("array data: %5s key %5d\n", array[i].key);
		}
	#endif
	printf("we have finish");
	return 0;
}
