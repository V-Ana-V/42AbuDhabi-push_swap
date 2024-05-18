/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_params_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:26:27 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/14 10:04:03 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b (t_nodes *a, t_nodes *b)
{
	t_nodes	*current_a;
	t_nodes	*target_node;
	long	best_match_value;

	while (b)
	{
		best_match_value = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if ((current_a->number > b->number)
			&& (current_a->number < best_match_value))
			{
				best_match_value = current_a->number;
				target_node = current_a;
			}
		current_a = current_a->next;
		}
		if (best_match_value == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_nodes *a, t_nodes *b)
{
    set_stack_indices(a);
    set_stack_indices(b);
    set_target_b(a, b);
}
