/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 09:12:51 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/14 09:13:04 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_nodes **stack, bool reverse)
{
	t_nodes	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	if (!reverse)
	{
		last_node->next = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		last_node->next->prev = last_node;
		last_node->next->next = NULL;
	}
	else
	{
		last_node->prev->next = NULL;
		last_node->next = *stack;
		last_node->prev = NULL;
		*stack = last_node;
		last_node->next->prev = last_node;
	}
}

void	r_one(t_nodes **stack, char stack_name, bool reverse)
{
	rotate(stack, reverse);
	if (reverse)
		ft_printf("rr%c\n", stack_name);
	else
		ft_printf("r%c\n", stack_name);
}

void	r_both(t_nodes **a, t_nodes **b, bool reverse)
{
	rotate(a, reverse);
	rotate(b, reverse);
	if (reverse)
		ft_printf("rrr\n");
	else
		ft_printf("rr\n");
}
