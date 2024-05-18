/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:38:24 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/08 14:38:29 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3nodes(t_nodes **a)
{
	t_nodes	*max_node;

	max_node = find_max(*a);
	if (max_node == *a)
		r_one(a, 'a', 0);
	else if ((*a)->next == max_node)
		r_one(a, 'a', 1);
	if ((*a)->number > (*a)->next->number)
		s_one(a, 'a');
}
