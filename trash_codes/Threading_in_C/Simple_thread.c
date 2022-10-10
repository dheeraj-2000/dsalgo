#include <pthread.h>
#include <stdlib.h>

/** create a thread
 *
 */

static void *ThreadFunc(){ //whatever you want the thread to do

    sleep(1);
    printf("Printing Thread");
    return  NULL;
}
int main(){

    pthread_t thread_id;
    printf("Before thread");
    pthread_create(&thread_id,NULL,ThreadFunc,NULL);
    pthread_join(thread_id,NULL);
    printf("After Thread");
    exit(0);

}

// execute with gcc -pthread main.c && ./a.out
