#include <stdio.h>
#include <unistd.h>


int main()
{
    pid_t t;
    t = fork();
    if (t == 0)
    {
        printf("Child having id %d\n", getpid());
    }
    else
    {
    	sleep(3);
        printf("Parent having id %d\n", getpid());
        //sleep(15); // Parent sleeps. Run the ps command during this time
    }
}

// To avoid zombie process:
// #include <sys/wait.h>
// In else part, use
// wait(NULL);
