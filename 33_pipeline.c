#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pid_t pid;

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    // Fork a child process to run the cat command
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        close(fd[0]);   // Close the read end of the pipe
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to the write end of the pipe
        execl("/bin/cat", "cat", "f2.txt", NULL); // Run the cat command
        perror("execl");
        exit(1);
    }

    // Parent process
    close(fd[1]);   // Close the write end of the pipe
    pid = fork();   // Fork another child process to run the tr command
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        dup2(fd[0], STDIN_FILENO);  // Redirect stdin to the read end of the pipe
        execl("/usr/bin/tr", "tr", "a-z", "A-Z", NULL); // Run the tr command
        perror("execl");
        exit(1);
    }

    // Parent process
    close(fd[0]);   // Close the read end of the pipe
    wait(NULL);     // Wait for the child processes to finish
    wait(NULL);

    return 0;
}

