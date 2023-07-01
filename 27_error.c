#include <stdio.h>
#include <errno.h>

int main() {
    // Print all error messages
    for(int i = 0; i < 100; i++) 
    {
        errno = i;
	perror("Error: ");        
    }

    return 0;
}

