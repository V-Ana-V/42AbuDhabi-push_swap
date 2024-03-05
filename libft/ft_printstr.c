/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 05:05:36 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/13 17:58:20 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	ssize_t	re;
	int		i;

	if (!s)
	{
		re = write(1, "(null)", 6);
		if (re == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		re = write(1, s + i++, 1);
		if (re == -1)
			return (-1);
	}
	return (i);
}
