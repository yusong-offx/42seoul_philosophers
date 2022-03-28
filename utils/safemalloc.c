#include "../includes/headerfile.h"

void    *safe_malloc(int size)
{
    void    *ret;

    ret = malloc(size);
    if (!ret)
        error_exit("Malloc");
    return (ret);
}