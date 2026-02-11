#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack; //Stores the current head node in first
	second = first->next; //Stores the second node in second
	first->next = second->next;//skeep the second node to the third 
	if (second->next)
		second->next->prev = first;// the third node its preveuis become the second
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	//finally we swap 2 nodes had zft.
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}