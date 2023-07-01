#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

//sender.c program

int main()
{
    int res, n;
    
    res = open("fifo1", O_WRONLY);
    write(res, "Message", 7);
    
    printf("Sender Process having PID %d sent the data\n", getpid());
}

// Nothing prints on the screen because it works in block mode,
// Unless there is receiver to receive the data, it won't work.
