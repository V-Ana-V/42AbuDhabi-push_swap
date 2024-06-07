/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:55:56 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:35:27 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nodes	*find_max(t_nodes *stack)
{
	int		max;
	t_nodes	*max_node;

	if (!stack)
		return (NULL);
	max = stack->number;
	max_node = stack;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_nodes	*find_min(t_nodes *stack)
{
	int		min;
	t_nodes	*min_node;

	if (!stack)
		return (NULL);
	min = stack->number;
	min_node = stack;
	while (stack)
	{
		if (stack->number < min)
		{
			min = stack->number;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

int	extremum(int x, int y, bool max)
{
	if (max == true)
	{
		if (x > y)
			return (x);
		return (y);
	}
	else
	{
		if (x < y)
			return (x);
		return (y);
	}
}
