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

bool	is_number(char *s)
{
	if (!s || !(*s))
        return (false);
	if (!(ft_isdigit(*s) || *s == '+' || *s == '-'))
		return (false);
	else if ((*s == '+' || *s == '-') && (!(*(s + 1)) || !(ft_isdigit(*(s + 1)))))
		return (false);
	s++;
	while (*s)
	{
		if (!(ft_isdigit(*s)))
			return (false);
		s++;
	}
	return(true);
}

void	non_numbers_check(t_arr	args)
{
	int	i;

	i = 0;
	while (i < args.len)
	{
		if (!is_number(args.arr[i]))
		{
			free_array(&args);
			write(2, "Error3\n", 7);
			exit(1);
		}
		i++;
	}
}

bool	duplicates_present(t_nodes	*stack, int	n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == n)
		{
			printf("node number is %d, and the adding number is %d\n", stack->number, n);
			return (true);
		}
		printf("stack pointer is %p, and stack->next pointer is %p\n", stack, stack->next);
		stack = stack->next;
	}
	return (false);
}

// void free_and_exit(t_nodes **stack)
// {
// 	free_stack(stack);
// 	ft_printf("Error\n");
// 	exit(1);
// }

// int main(int ac, char **av)
// {
// 	(void) ac;
// 	printf("%d\n", is_number(av[1]));
// 	return(0);
// }
