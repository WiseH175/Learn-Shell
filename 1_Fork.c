#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t q;

printf("before fork\n");

q = fork();

if(q < 0)
	printf("Error");

else if(q == 0)
{
	//q = fork();    // child of child 
	printf("I am child having id %d\n",getpid());
	printf("My parent's id is %d\n",getppid());
}
else         // q > 0
{
	printf("I am parent having id %d\n",getpid());
	printf("My child's id is %d\n",q);	
}

printf("Common\n");
}

