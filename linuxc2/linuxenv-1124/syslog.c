#include <syslog.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE * f;
    f = fopen("nothere", "r");
    if(!f) {
        syslog(LOG_ERR|LOG_USER, "OOPS - %m\n");
        exit(1);
    }
}