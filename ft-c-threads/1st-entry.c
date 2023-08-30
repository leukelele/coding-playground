#include <stdio.h>      // for the 'printf' function
#include <pthread.h>    // for the initialization of the thread identifier and thread creation

/**
 * @brief executed as a result of the 'pthread_create'
 * 
 * @return void* 
 */
void * threadFunc() {
    printf("Entered 'threadFunc()'\n");
    
    printf("Exiting 'threadFunc()'\n");
    return NULL;
}

int main() {
    
    pthread_t threadID;
    printf("Leaving main\n");
    pthread_create(&threadID, NULL, threadFunc, NULL);
    printf("Return to main\n");
    pthread_join(threadID, NULL);
}