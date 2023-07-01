#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

void *thread_function(void *arg);
int num[2] = {3, 5};

int main()
{
    void *result;
    pthread_t a_thread;
    
    pthread_create(&a_thread, NULL, thread_function, (void *)num);
    pthread_join(a_thread, &result);
    
    printf("Inside main:\n");
    // printf("Thread returned: %s\n", (char*) result);
    printf("%ld\n", (intptr_t)result);
}

void *thread_function(void *arg)
{
    int *x = arg;
    int sum = x[0] + x[1];
    printf("Sum is %d\n", sum);
    pthread_exit((void *)(intptr_t)sum);
}
