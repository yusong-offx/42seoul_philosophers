#include "../includes/headerfile.h"

void *philo_fun(void *s)
{
    sleep(1);
    printf("Thread Hello Wolrd!\n");
    return (0);
}

int main(int argc, char **argv)
{
    pthread_t   tid;
    t_philo     *philo;
    int         info[argc-1];

    init_info(info, argv);
    pthread_create(&tid, NULL, philo_fun, NULL);
    // pthread_detach(tid);
    pthread_join(tid, NULL);
    printf("main end\n");

    exit(0);
}