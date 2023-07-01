#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>


int main()
{
	void *shared_memory;
	char buff[100];
	
	int shmid = shmget((key_t)2345, 1024, 0666);
	
	shared_memory = shmat(shmid, NULL, 0);
	
	printf("%s", (char *)shared_memory);

}
