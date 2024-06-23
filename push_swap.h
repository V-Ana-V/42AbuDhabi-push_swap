/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:34:36 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:34:39 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_nodes
{
	int				number;
	int				index;
	int				cost_p;
	bool			above_med;
	bool			cheapest;
	struct s_nodes	*target;
	struct s_nodes	*next;
	struct s_nodes	*prev;
}	t_nodes;

typedef struct s_arr
{
	char	**arr;
	int		len;
	bool	malloc_fail;
}	t_arr;

//parse1.c parse2.c
void	free_array(t_arr *result);
t_arr	parse_one(char const *s);
t_arr	make_args(int ac, char **av);

//check_err.c
bool	is_number(char *s);
void	non_numbers_check(t_arr	args);
bool	duplicates_present(t_nodes *stack, int n);
void	free_and_exit(t_nodes **stack, t_arr *arr);
void	free_and_exit_args_only(t_arr *arr);

//create_stack_a.c
void	build_stack_a(t_nodes **stack_a, t_arr *args);
void	free_stack(t_nodes	**stack);
t_nodes	*find_last(t_nodes *stack);

//rotate.c and push_swap_cmnds.c
void	r_one(t_nodes **stack, char stack_name, bool reverse);
void	r_both(t_nodes **a, t_nodes **b, bool reverse);
void	push(t_nodes **to, t_nodes **from, char to_stack_name);
void	s_one(t_nodes **stack, char stack_name);
void	s_both(t_nodes **a, t_nodes **b);

//utils1.c & utils2.c
bool	already_sorted(t_nodes *stack);
int		st_len(t_nodes *stack);
t_nodes	*get_cheapest(t_nodes *stack);
t_nodes	*find_max(t_nodes *stack);
void	node_to_top(t_nodes **stack, t_nodes *top_node, char stack_name);
t_nodes	*find_min(t_nodes *stack);
int		extremum(int x, int y, bool max);

//set_nodes_params_a.c & set_nodes_params_b.c
void	set_stack_indices(t_nodes *stack);
void	set_cheapest(t_nodes *stack);
void	init_nodes_a(t_nodes *a, t_nodes *b);
void	init_nodes_b(t_nodes *a, t_nodes *b);

//sort_3nodes.c
void	sort_3nodes(t_nodes **a);

//sort.c
void	sort_stacks(t_nodes **a, t_nodes **b);

#endif
