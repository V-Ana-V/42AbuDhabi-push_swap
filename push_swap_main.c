/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:57:07 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:34:15 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nodes	*a;
	t_nodes	*b;
	t_arr	args;

	a = NULL;
	b = NULL;
	args = make_args(ac, av);
	if (args.arr == NULL && args.malloc_fail == false)
		return (0);
	if (args.arr == NULL && args.malloc_fail == true)
	{
		write(2, "MemErr\n", 7);
		exit(1);
	}
	non_numbers_check(args);
	build_stack_a(&a, args);
	if (!already_sorted(a))
	{
		if (st_len(a) == 2)
			s_one(&a, 'a');
		else if (st_len(a) == 3)
			sort_3nodes(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
