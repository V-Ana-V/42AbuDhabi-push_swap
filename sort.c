/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:14:13 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/10 09:14:16 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_together(t_nodes **a, t_nodes **b,
	t_nodes *cheapest_node, bool rev)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		r_both(a, b, rev);
	set_stack_indices(*a);
	set_stack_indices(*b);
}

static void	move_a_to_b(t_nodes **a, t_nodes **b)
{
	t_nodes	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_med && cheapest_node->target->above_med)
		rotate_together(a, b, cheapest_node, false);
	else if (!(cheapest_node->above_med) && !(cheapest_node->target->above_med))
		rotate_together(a, b, cheapest_node, true);
	node_to_top(a, cheapest_node, 'a');
	node_to_top(b, cheapest_node->target, 'b');
	push(b, a, 'b');
}

static void	move_b_to_a(t_nodes **a, t_nodes **b)
{
	node_to_top(a, (*b)->target, 'a');
	push(a, b, 'a');
}

static void	min_to_top(t_nodes **a)
{
	t_nodes	*min;

	min = find_min(*a);
	while ((*a)->number != min->number)
	{
		if (min->above_med)
			r_one(a, 'a', false);
		else
			r_one(a, 'a', true);
	}
}

void	sort_stacks(t_nodes **a, t_nodes **b)
{
	int	len_a;

	len_a = st_len(*a);
	if (len_a-- > 3 && !already_sorted(*a))
		push(b, a, 'b');
	if (len_a-- > 3 && !already_sorted(*a))
		push(b, a, 'b');
	while (len_a-- > 3 && !already_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3nodes(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_stack_indices(*a);
	min_to_top(a);
}
