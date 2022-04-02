#include "../includes/headerfile.h"

suseconds_t get_time(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_usec);
}

// void    eat(int i)
// {

// }

// void    sleep(int i)
// {

//     printf();
// }

// void    day(int i)
// {

// }

void    live()
{
    pthread_t   tid[g_phoinfo.num];
    int i;

    i = 0;
    while (i < g_phoinfo.num)
    {
        printf("%p\n", &tid[i]);
        i++;
    }
    g_start = get_time();
}