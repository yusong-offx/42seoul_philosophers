#include "../includes/headerfile.h"

void *philo_fun(void *s)
{
    usleep(1000000);
    printf("Thread Hello Wolrd!\n");
    return (0);
}

void    error_exit(char *msg)
{
    printf("%s error\n", msg);
    exit(1);
}

int main(int argc, char **argv)
{
    int         info[argc-1];

    // argv 유효성검사
    init_info(info, argv);
    init_phoinfo(info);
    if (argc == 6)
        init_philo(info[4]);
    else
        init_philo(-1);
    printf("%d %d %d %d\n", g_phoinfo.num, g_phoinfo.die, g_phoinfo.eat, g_phoinfo.sleep);
    
    printf("main end\n");
    return (0);
}