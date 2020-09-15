#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define n 100000
int buffer[n];
int counter = 0;
pthread_cond_t producer_r;
pthread_cond_t consumer_r;
pthread_mutex_t lock;


void *produce(void *args) ;

void *consume(void *args) ;

int main() {
    pthread_t producer;
    pthread_create(&producer, NULL, &produce, NULL);
    pthread_t consumer;
    pthread_create(&consumer, NULL, &consume, NULL);
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    return 0;
}
void *produce(void *args) {
    while (1) {
        printf("I am in producer\n");
        fflush(stdout);
        if (counter == n) pthread_cond_wait(&consumer_r, &lock);
        buffer[counter] = rand() % 100;
        counter += 1;
        if (counter == 1) pthread_cond_signal(&producer_r);

    }
}
void *consume(void *args) {
    while (1) {
        usleep(40000);
        printf("I am in consumer\n");
        fflush(stdout);
        if (counter == 0) pthread_cond_wait(&producer_r, &lock);
        counter -= 1;
        if (counter == (n - 1)) pthread_cond_signal(&consumer_r);
        //printf("Buffer item %d\n", buffer[counter]);
        //fflush(stdout);
    }
}
