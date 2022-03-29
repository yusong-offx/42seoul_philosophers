#include "../includes/headerfile.h"

t_phoinfo   g_phoinfo;

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
    init_phoinfo(&g_phoinfo, info);

    
    printf("main end\n");
    return (0);
}