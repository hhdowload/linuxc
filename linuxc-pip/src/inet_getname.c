#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char *host, **names, **addrs;
    struct hostent *hostinfo;

    if(argc == 1) {
        char myname[256];
        gethostname(myname, 255);
        host = myname;
    } else host = argv[1];


    hostinfo = gethostbyname(host);
    if(!hostinfo) {
        fprintf(stderr, "get host=%s info failed\n", host);
        exit(1);
    }

    printf("result for hosts %s:\n", host);
    printf("Name:%s\n",hostinfo->h_name);
    printf("Aliases:");
    names = hostinfo->h_aliases;
    while(*names) {
        printf("%s", *names);
        names++;
    }
    printf("\n");

    if(hostinfo->h_addrtype != AF_INET) {
        fprintf(stderr, "not a ip host!\n");
        exit(1);
    }

    addrs = hostinfo->h_addr_list;
    while(*addrs) {
        fprintf(stderr, inet_ntoa(*(struct in_addr *)addrs));
        addrs++;
    }

    printf("\n");
    exit(0);

}

