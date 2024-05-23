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
