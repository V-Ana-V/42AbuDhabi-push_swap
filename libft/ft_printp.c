/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:13:25 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/13 18:11:02 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptrhex(uintptr_t p)
{
	int		count;
	int		re;
	char	d;
	char	*hex;

	hex = "0123456789abcdef";
	count = 0;
	if (p / 16 != 0)
		count += ft_ptrhex(p / 16);
	d = hex[p % 16];
	re = write(1, &d, 1);
	if (re == -1)
		return (-1);
	count++;
	return (count);
}

int	ft_printp(void *ptr)
{
	int			re;
	uintptr_t	p;

	if (ptr == NULL)
	{
		re = write(1, "0x0", 3);
		if (re == -1)
			return (-1);
		return (3);
	}
	re = write(1, "0x", 2);
	if (re == -1)
		return (-1);
	p = (uintptr_t) ptr;
	re = ft_ptrhex(p);
	if (re == -1)
		return (-1);
	return (re + 2);
}
