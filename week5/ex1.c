#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* Firstly we create first thread using pthread_create. Then first thread prints message about creation.
After it send us message from ThreadFun function. Then it finished work and turn go to second thread and so on. */
int k = 0;

// The function to be executed by all threads
void *ThreadFun(void) {
    printf("Hello from thread %d\n", k);
    return NULL;
}

int main() {
    int n = 3;
    pthread_t *thread = malloc(sizeof(pthread_t) * n);

    // Let us create n threads
    for (int i = 0; i < n; i++) {
        pthread_create(&thread[i], NULL, (void *(*)(void *)) ThreadFun, NULL);
        printf("Thread %d created\n", i);
        pthread_join(thread[i], NULL);
        k++;
    }
    return 0;
}