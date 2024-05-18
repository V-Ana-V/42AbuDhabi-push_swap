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

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_nodes	*a;
	t_nodes	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 || av[1][0] == '\0'))
		return (1);
	else if (ac == 2)
		av = split(av[1], ' ');
	init_st_a(&a, av + 1);
	if (!sorted(a))
	{
		if (st_len(a) == 2)
			sa (&a, false);
		else if (st_len(a) == 3)
			sort_3nodes(&a) ;
		else
			sort_stacks(&a, &b);
	}
	free_st(&a);
	return (0);
}

