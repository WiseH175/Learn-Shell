#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *fp1, *fp2;
    char buffer[BUFFER_SIZE];

    fp1 = fopen("filename.txt", "r");
    fp2 = fopen("f2.txt", "w");

    while (fgets(buffer, BUFFER_SIZE, fp1)) {
        fputs(buffer, fp2);
    }
    
    fclose(fp1);
    fclose(fp2);

    system("cat f2.txt");
    
    return 0;
}

