#include <stdlib.h>
#include <stdio.h>

int main() {
    char * filename;
    FILE * fstream;
    char  tmpname[L_tmpnam];

    filename = tmpnam(tmpname);
    printf("make a tmpfile %s\n", filename);

    fstream = tmpfile();
    if(tmpfile) {
        printf("we open this file\n");
    }
    else {
        perror("openfailde");
    }

    exit(0);

}