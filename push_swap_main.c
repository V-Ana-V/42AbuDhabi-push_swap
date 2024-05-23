/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:57:07 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/02 11:57:12 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nodes	*a;
	t_nodes	*b;
	t_nodes	*node;
	t_arr	args;
	int		i;

	a = NULL;
	b = NULL;
	args = make_args(ac, av);
	printf("//make_args//\n");
	if (args.arr == NULL && args.malloc_fail == false)
		return (printf("//make_args//no args\n"), 0);
	if (args.arr == NULL && args.malloc_fail == true)
	{
		printf("//make_args//malloc failed\n");
		write(2, "MemErr\n", 7);
		exit(1);
	}
	printf("//start non numbers check//\n");
	non_numbers_check(args);
	printf("//done non numbers check//no arg\n");
	build_stack_a(&a, args);
	printf("%p\n", a);
	node = a;
	while (node)
	{
		printf("Number in stack is %d\n", node->number);
		node = node->next;
	}
	// if (!sorted(a))
	// {
	// 	if (st_len(a) == 2)
	// 		sa (&a, false);
	// 	else if (st_len(a) == 3)
	// 		sort_3nodes(&a) ;
	// 	else
	// 		sort_stacks(&a, &b);
	// }
	// free_st(&a);
	return (0);
}
