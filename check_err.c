/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:26:03 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/17 10:26:06 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_number(char *s)
{
	if (!s || !(*s)) // Check if the string is NULL or empty
        return (1);
	if (!(ft_isdigit(*s) || *s == '+' || *s == '-'))
		return (1);
	else if ((*s == '+' || *s == '-') && (!(*(s + 1)) || !(ft_isdigit(*(s + 1)))))
		return (1);
	s++;
	while (*s)
	{
		if (!(ft_isdigit(*s)))
			return (1);
		s++;
	}
	return(0);
}

int	duplicates_present(t_nodes	*stack, int	n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
			return (1);
		stack = stack->next;
	}
	return (0);
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

void free_and_exit(t_nodes **stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(1);
}
