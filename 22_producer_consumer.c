#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
sem_t empty, full;
int in = 0;
int out = 0;

void *producer(void *arg)
{
    int item;
    while (in < 4) {
        // Generate a random item
        item = rand() % 100;

        // Wait for an empty slot in the buffer
        sem_wait(&empty);

        // Produce the item and add it to the buffer
        buffer[in] = item;
        printf("Produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        // Signal that the buffer is no longer empty
        sem_post(&full);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    int item;
    while (out < 4) {
        // Wait for a full slot in the buffer
        sem_wait(&full);

        // Consume an item from the buffer
        item = buffer[out];
        printf("Consumed item %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;

        // Signal that the buffer is no longer full
        sem_post(&empty);

        // Sleep for a random amount of time
        usleep(rand() % 1000000);
    }
    pthread_exit(NULL);
}

int main()
{
    // Initialize the semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create the producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the threads to exit
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the semaphores
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

