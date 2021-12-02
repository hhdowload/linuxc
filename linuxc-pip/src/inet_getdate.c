#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char *host, **names, **addrs;
    struct hostent *hostinfo;
    int sockfd, len;
    char buffer[128];

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
    printf("Name:%s\n",hostinfo->h_name);
    if(hostinfo->h_addrtype != AF_INET) {
        fprintf(stderr, "not a ip host!\n");
        exit(1);
    }

    struct servent *servinfo;
    servinfo = getservbyname("daytime", "tcp");
    if(!servinfo) {
        fprintf(stderr, "no daytime service\n");
        exit(1);
    }
    printf("datetime port=====>%d\n", ntohs(servinfo -> s_port ));

    struct sockaddr_in sock_addr;
    int res;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;//看不懂；
    sock_addr.sin_port = servinfo->s_port;
    len = sizeof(sock_addr);

    res = connect(sockfd, (void *)&sock_addr, len);
    if(res == -1 ) {
        perror("connect failed");
        exit(1);
    }

    res = read(sockfd, buffer, sizeof(buffer));
    buffer[res] = '\0';
    printf("read %d bytes: %s", res, buffer);

    close(sockfd);
    exit(0);


    printf("\n");
    exit(0);

}

