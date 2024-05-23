#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_nodes
{
	int             number;
	int             index;
	int             cost_p;
	bool            above_med;
	bool            cheapest;
	struct s_nodes  *target;
	struct s_nodes  *next;
	struct s_nodes  *prev;
}   t_nodes;

typedef struct s_arr
{
	char	**arr;
	int		len;
	bool	malloc_fail;
}   t_arr;

//parse1.c parse2.c
void	free_array(t_arr *result);
t_arr	parse_one(char const *s);
t_arr	make_args(int ac, char **av);

//check_err.c
bool	is_number(char *s);
void	non_numbers_check(t_arr	args);
bool	duplicates_present(t_nodes	*stack, int	n);

//create_stack_a.c
void	build_stack_a(t_nodes **stack_a, t_arr args);
void	free_stack(t_nodes	**stack);
t_nodes	*find_last(t_nodes *stack);

//rotate.c and push_swap_cmnds.c
void	r_one(t_nodes **stack, char stack_name, bool reverse);
void    r_both(t_nodes **a, t_nodes **b, bool reverse);
void    push(t_nodes **to, t_nodes **from, char from_stack_name);
void    s_one(t_nodes **stack, char stack_name);
void    s_both(t_nodes **a, t_nodes **b);

//stack_part1.c & utils_part2.c
t_nodes	*get_cheapest(t_nodes *stack);
void	node_on_top(t_nodes **stack, t_nodes *top_node, char stack_name);
bool    already_sorted(t_nodes *stack);
int     st_len(t_nodes  *stack);
t_nodes *find_min(t_nodes *stack);
t_nodes *find_max(t_nodes *stack);

//sort_3nodes.c
void    sort_3nodes(t_nodes **a);

//set_nodes_params_a.c & set_nodes_params_b
void    init_nodes_a(t_nodes *a, t_nodes *b);
void	init_nodes_b(t_nodes *a, t_nodes *b);
void	set_stack_indices(t_nodes *stack);

//sort.c
void    sort_stacks(t_nodes **a, t_nodes **b);

#endif