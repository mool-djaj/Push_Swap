#ifndef PUSH_SWAP
 #define PUSH_SWAP

#include "libft/libft.h"
# include "get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

typedef struct stack
{
	int value;
	int index;
	int pos;
	int target_pos;
	int val_a;
	int val_b;
	int cheap;
	struct stack *next;
	struct stack *prev;
} t_stack;

void add_stack_to(t_stack **stack, t_stack *new_nodde);
t_stack	*creat_stack(int nbr);
t_stack	*get_stack_last(t_stack *stack);
void free_stack(t_stack **sta);
int	ft_atol(const char *str, long *nptr);
void add_stack_to(t_stack **stack, t_stack *new_nodde);
int duplicate_num(t_stack *a, int nmb);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	free_split(char **args);
int	fill_stack(t_stack **sta, char *arg);
void sort3(t_stack **a);
int is_sorted(t_stack *sta);
t_stack *find_max(t_stack *sta);
int stack_len(t_stack *sta);
void set_price(t_stack*a, t_stack *b);
t_stack *find_min(t_stack *sta);
void set_target_a(t_stack *a, t_stack *b);
void move_to_b(t_stack **a, t_stack **b);
t_stack *get_cheapest(t_stack *stack);
void cheapest(t_stack *a);
void set_price(t_stack*a, t_stack *b);
void set_target_b(t_stack *a, t_stack *b);
void big_sort(t_stack **a, t_stack **b);
int stack_len(t_stack *sta);
int	ft_abs(int n);
void set_current_pos(t_stack *sta);
void push_back(t_stack **a, t_stack **b);
void final_check(t_stack **a);
void rotate_both(t_stack **a, t_stack **b, t_stack *cheap);
t_stack *get_target_node_a(t_stack *a, t_stack *b_node);

void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **dest, t_stack **src);

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
