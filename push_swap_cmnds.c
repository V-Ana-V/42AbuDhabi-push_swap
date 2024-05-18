/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cmnds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:06:37 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/16 12:50:58 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_nodes **to, t_nodes **from, char from_stack_name)
{
    t_nodes *push_node;

    if (!(*from))
        return ;
    push_node = *from;
    *from = (*from)->next;
    if (*from)
        (*from)->prev = NULL;
    if (!(*to))
    {
        *to = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *to;
        (*to)->prev = push_node;
		*to = push_node;
    }
	ft_printf("p%c\n", from_stack_name);
}

static void	swap(t_nodes **stack)
{
    t_nodes *a1;
    t_nodes *a2;

    if (!(*stack) || !(*stack)->next)
        return ;
    a1 = *stack;
    a2 = (*stack)->next;
    a1->next = a2->next;
    if (a2->next)
        a2->next->prev = a1;
    a2->prev = NULL;
    a2->next = a1;
    a1->prev = a2;
    *stack = a2;
}

void    s_one(t_nodes **stack, char stack_name)
{
    swap(stack);
    ft_printf("s%c\n", stack_name);
}

void    s_both(t_nodes **a, t_nodes **b)
{
    swap(a);
    swap(b);
    ft_printf("ss\n");
}
