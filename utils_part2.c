/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 10:55:56 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/08 10:55:59 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	st_len(t_nodes  *stack)
{
    int l;

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

t_nodes	*find_last(t_nodes *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool already_sorted(t_nodes *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->number > stack->next->number)
            return (0);
        stack = stack->next;
    }
    return (1);
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

t_nodes *find_max(t_nodes *stack)
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
