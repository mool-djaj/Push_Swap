#ifndef PUSH_SWAP
 #define PUSH_SWAP

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>

typedef struct stack
{
	int value;
	int index;
	int pos;
	int target_pos;
	int val_a;
	int val_b;
	struct stack *next;
	struct stack *prev;
} t_stack;

void add_stack_to(t_stack **stack, t_stack *new_nodde);
t_stack	*creat_stack(int nbr);
t_stack	*get_stack_last(t_stack *stack);
void free_stack(t_stack **sta);
int	ft_atol(const char *str, long *nptr);
void add_stack_to(t_stack **stack, t_stack *new_nodde);
int dublicate_num(t_stack *a, int nmb);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **args);
int	fill_stack(t_stack **sta, char *arg);

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);


#endif
