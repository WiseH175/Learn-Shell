#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
    pid_t p;
    int w1, wstatus;
    
    printf("before fork\n");
    p = fork();
    
    
    if (p == 0) 			// child
    {
    	//sleep(3);
        printf("I am child having id %d\n", getpid());
        printf("My parent's id is %d\n", getppid());
    }
    else 				// parent
    {
        //wait(NULL); 			// parent wait for child
        
        w1 = wait(&wstatus);
        printf("Status: %d\n", WIFEXITED(wstatus)); 
        printf("PID 0f Child is : %d\n", w1);
        
        printf("I am parent having id %d\n", getpid());
        printf("My child's id is %d\n", p);
    }
    
    printf("Common\n");
}
