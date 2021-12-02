#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    int opt;
    char *c;
    c = "heloe";
    while((opt = getopt(argc, argv, ":ir:lf")) != -1 ) {
        switch(opt) {
            case 'i' :
            case 'f' :
            case 'l' :
                printf("paras option===>%c\n", opt);
                break;
            case 'r' :
                printf("paras file====>%s\n", optarg);
                break;
            default : 
                printf("error usage: %s -i -r file -l -f\n`", argv[0]);
                printf("%o ----%s------%o------%s\n", argv, *argv, &argv[0], c);
                exit(1);
        }
    }

    exit(EXIT_SUCCESS);
}