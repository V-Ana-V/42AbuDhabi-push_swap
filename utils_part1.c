/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 09:41:50 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/08 10:52:40 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	number;
	int		sign;

	number = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (s == '-' || s == '+')
	{
		if (s == '-')
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

static void	node_append(t_nodes	**stack, int n)
{
	t_nodes	*new_node;
	t_nodes	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_nodes));
	if (!new_node)
		return ;
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

void    build_stack_a(t_nodes **stack_a, char **av) //should we start from i=0?
{
    long    n;
    int     i;

    i = 0;
    while (av[i])
    {
        if(error_syntax(av[i]))
            free_errors(stack_a);
        n = ft_atol(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(stack_a);
        if (error_duplicate(*stack_a, (int)n))
            free_errors(stack_a);
        node_append(stack_a, (int)n);
    }
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

void	node_on_top(t_nodes **stack, t_nodes *node_to_move, char stack_name)
{
	while (*stack != node_to_move)
	{
		if (node_to_move->above_med)
			r_one(stack, stack_name, 0);
		else
			r_one(stack, stack_name, 1);
	}
}
