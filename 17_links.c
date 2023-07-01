#include <stdio.h>
#include <stdlib.h>

int main() {
    //char filename[] = "filename.txt";

    // File type
    system("file filename.txt");

    // Number of links
    system("ls -l filename.txt | awk '{print $2}'");

    // Time of last access
    system("ls -l filename.txt | awk '{print $6, $7}'");

    // Read, write, and execute permission
    system("ls -l filename.txt | awk '{print $1}'");

    return 0;
}

