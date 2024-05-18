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

static void move_a_to_b(t_nodes **a, t_nodes **b)
{
	t_nodes	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_med && cheapest_node->target->above_med)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_med) && !(cheapest_node->target->above_med))
		rrorate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target, 'b');
	pb(b, a, false);
}

void    sort_stacks(t_nodes **a, t_nodes **b)
{
	int len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !already_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !already_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !already_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_3nodes(a);
	while(*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_stack_indices(*a);
	min_on_top(a);
}
