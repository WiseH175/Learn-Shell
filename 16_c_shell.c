#include <stdlib.h>
#include<stdio.h>

int main() {
    int status;
    status = system("./script.sh");

    if (status == -1) {
        printf("Error running script.\n");
    } else {
        printf("Script executed successfully.\n");
    }

    return 0;
}

