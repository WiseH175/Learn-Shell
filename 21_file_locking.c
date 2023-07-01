#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <semaphore.h>
#include <unistd.h>

int main() {
    int fd;
    sem_t lock;
    
    char buffer[1000];

    // Open the file
    fd = open("filename.txt", O_CREAT | O_RDWR | O_APPEND, 0666);
    if (fd < 0) {
        perror("open error");
        exit(1);
    }

    // Initialize the semaphore
    if (sem_init(&lock, 1, 1) < 0) {
        perror("sem_init error");
        exit(1);
    }

    // Wait for the semaphore
    if (sem_wait(&lock) < 0) {
        perror("sem_wait error");
        exit(1);
    }

    // Write to the file
    printf("Writing to file...\n");
    write(fd, "Hello, world!\n", 14);
    
    system("cat filename.txt");

    // Release the semaphore
    if (sem_post(&lock) < 0) {
        perror("sem_post error");
        exit(1);
    }
    

    // Close the file and semaphore
    close(fd);
    sem_destroy(&lock);

    return 0;
}

