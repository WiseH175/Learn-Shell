#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    while (1) {
        time_t now = time(NULL);
        printf("Current time: %s", ctime(&now));
        sleep(6);
    }
    return 0;
}

