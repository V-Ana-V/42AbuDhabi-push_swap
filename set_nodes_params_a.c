/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes_params_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:26:27 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/14 10:03:50 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_indices(t_nodes *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a (t_nodes *a, t_nodes *b)
{
	t_nodes	*current_b;
	t_nodes	*target_node;
	long	best_match_value;

	while (a)
	{
		best_match_value = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if ((current_b->number < a->number)
			&& (current_b->number > best_match_value))
			{
				best_match_value = current_b->number;
				target_node = current_b;
			}
		current_b = current_b->next;
		}
		if (best_match_value == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void set_cost_a(t_nodes *a, t_nodes *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while(a)
	{
		a->cost_p = a->index;
		if(!(a->above_med))
			a->cost_p = len_a - (a->index);
		if(a->target->above_med)
			a->cost_p += a->target->index;
		else
			a->cost_p += len_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_nodes *stack)
{
	long	cheapest_cost;
	t_nodes	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		if (stack->cost_p < cheapest_cost)
		{
			cheapest_cost = stack->cost_p;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_nodes *a, t_nodes *b)
{
    set_stack_indices(a);
    set_stack_indices(b);
    set_target_a(a, b);
    set_cost_a(a,b);
    set_cheapest(a);
}
