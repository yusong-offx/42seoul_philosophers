#include "../includes/headerfile.h"

pthread_t *g_tid;

void *philo_fun(void *s)
{
    usleep(1000000);
    printf("Thread Hello Wolrd!\n");
    return (0);
}

void    error_exit(char *msg)
{
    printf("%s error\n", msg);
    // 쓰레드해제
    // pthread_detach(쓰레드id);
    exit(1);
}

int main(int argc, char **argv)
{
    pthread_t   tid;
    t_philo     *philo;
    int         info[argc-1];

    init_info(info, argv);
    printf("%ld\n", sizeof(g_tid));
    pthread_create(&tid, NULL, philo_fun, NULL);
    // pthread_detach(tid);
    pthread_join(tid, NULL);
    printf("main end\n");

    exit(0);
}