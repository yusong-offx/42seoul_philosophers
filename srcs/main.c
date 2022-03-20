#include "../includes/headerfile.h"

void *test(void *a)
{
    printf("Thread Hello Wolrd!\n");
    return (0);
}

int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, test, NULL);
    sleep(1);
    printf("Hello World!\n");
    exit(0);
}