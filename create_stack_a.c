/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:05:12 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:32:31 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	number;
	int		sign;

	sign = 1;
	number = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		if (number >= (LONG_MAX - (*s - '0')) / 10)
			return (LONG_MAX);
		number = number * 10 + (*s - '0');
		s++;
	}
	return (number * sign);
}

void	free_stack(t_nodes	**stack)
{
	t_nodes	*nxt;
	t_nodes	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node)
	{
		nxt = node->next;
		free(node);
		node = nxt;
	}
	*stack = NULL;
}

t_nodes	*find_last(t_nodes *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	node_append(t_nodes	**stack, int n)
{
	t_nodes	*new_node;
	t_nodes	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_nodes));
	if (!new_node)
	{
		free_stack(stack);
		return ;
	}
	new_node->next = NULL;
	new_node->number = n;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	build_stack_a(t_nodes **stack_a, t_arr args)
{
	long	n;
	int		i;

	i = 0;
	while (i < args.len)
	{
		n = ft_atol(args.arr[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_stack(stack_a);
			free_array(&args);
			write(2, "Error\n", 6);
			exit(1);
		}
		if (duplicates_present(*stack_a, (int)n))
		{
			free_stack(stack_a);
			free_array(&args);
			write(2, "Error\n", 6);
			exit(1);
		}
		node_append(stack_a, (int)n);
		i++;
	}
	free_array(&args);
}
