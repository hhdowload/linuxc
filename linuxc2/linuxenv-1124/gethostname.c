#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>


int main() {
    char computer[256];
    struct utsname uts;

    if(gethostname(computer, 255) != 0 || uname(&uts) < 0) {
        fprintf(stderr, "couldnt find host info\n");
        exit(1);
    }

    printf("computer host====>%s\n", computer);
    printf("system==>%s, hardware===>%s, nodename===>%s, version===>%s %s\n", uts.sysname, uts.machine, uts.nodename, uts.release, uts.version);
    exit(EXIT_SUCCESS);
}