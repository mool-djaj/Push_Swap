#include "push_swap.h"

t_stack	*creat_stack(int nbr)
{
    t_stack	*new_node;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);

    new_node->value = nbr;
    new_node->index = -1;
    
    new_node->pos = -1;
    new_node->target_pos = -1;
    new_node->val_a = -1;
    new_node->val_b = -1;
    
    new_node->next = NULL;
    new_node->prev = NULL;
    
    return (new_node);
}
