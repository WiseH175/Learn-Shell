#include<stdio.h>
#include<unistd.h>
int main()
{
    printf("Before execl\n");
    execl("/bin/ls","ls","-l",NULL);//
    printf("After execlp\n");
}
