#include "push_swap.h"

void free_stack(t_stack **sta)
{
    t_stack *tmp;
    t_stack *current;

    if (!sta || !*sta)
        return ;

    current = *sta;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }

    *sta = NULL;

}