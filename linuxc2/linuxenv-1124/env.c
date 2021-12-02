#include <stdio.h>
#include <stdlib.h>



int main(int argc, char * argv[]) {
    char * res;
    res = getenv("HOME");
    if(res) {
        printf("home has his value =>%s\n", res);
    } else printf("homeless\n");

    if(argc == 1 || argc > 3) {
        fprintf(stderr,"error usage: env arg [value]\n");
        exit(1);
    } 

    res = getenv(argv[1]);
    char buffer[100];
    if(res) {
        printf("%s has his value =>%s\n", argv[1], res);
    } else {
        printf("homeless\n");
        printf("%s = %s\n", argv[1], argv[2]);
        sprintf(buffer, "%s=%s", argv[1], argv[2]);
        
        if(putenv(buffer) == 0) {
            printf("BE NAMED BY %s = %s\n", argv[1], getenv(argv[1]));
        }
        else {
            perror("putenv failed");
            exit(EXIT_FAILURE);
        }
    }

    
    exit(0);
}