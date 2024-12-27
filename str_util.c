#include "push_swap.h"

int     ft_strcmp(const char *s1, const char *s2)
{
    unsigned int    iter;

    iter = 0;
    while((s1[iter] && s2[iter]) && s1[iter] == s2[iter])
        iter++;
    return (s1[iter] - s2[iter]);
}