/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:41:50 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:35:14 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	already_sorted(t_nodes *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

int	st_len(t_nodes *stack)
{
	int	l;

	if (!stack)
		return (0);
	l = 0;
	while (stack)
	{
		l++;
		stack = stack->next;
	}
	return (l);
}

t_nodes	*get_cheapest(t_nodes *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	node_to_top(t_nodes **stack, t_nodes *node_to_move, char stack_name)
{
	while (*stack != node_to_move)
	{
		if (node_to_move->above_med)
			r_one(stack, stack_name, 0);
		else
			r_one(stack, stack_name, 1);
	}
}
