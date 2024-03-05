/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:14:22 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/13 18:33:24 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printud(unsigned int nb)
{
	char			count;
	unsigned int	d;
	int				re;

	count = 0;
	if (nb / 10 != 0)
	{
		re = ft_printud(nb / 10);
		if (re == -1)
			return (-1);
		count += re;
	}
	d = nb % 10 + 48;
	if (write(1, &d, 1) == -1)
		return (-1);
	count++;
	return (count);
}
