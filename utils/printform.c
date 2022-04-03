#include "../includes/headerfile.h"

void    print_form(int i, char *s)
{
    printf("[%10ldms] %d %s\n", (get_time() - g_start) / 1000, i, s);
}