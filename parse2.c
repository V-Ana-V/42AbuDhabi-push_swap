/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:24:41 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/10 11:24:44 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arr_len (char **arr)
{
	int	l;

	if (arr == NULL)
		return (0);
	l = 0;
	while (*(arr + l))
		l++;
	return (l);
}

static void	free_arr(char ***arr)
{
	char	**tmp;

	if (*arr == NULL)
		return ;
	tmp = *arr;
	while(tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(*arr);
	*arr = NULL;
}

int	**final_arr_len(char **av)
{
	char	**av_nums;
	int		l;
	
	if (!av)
		return (NULL);
	l = 0;
	while (*av)
	{
		av_nums = ft_split(*av, 1);
		if (!av_nums)
			return (0);
		l = l + arr_len(av_nums);
		free_arr(&av_nums);
	}
	return (l);
}

void	fill_nums(char **av, char **nums, char ***final_arr)
{
	int		l;
	int		i;

	i = 0;
	if (av == NULL)
		return ;
	l = final_arr_len(**av);
	*final_arr = (char **)malloc((l + 1)*sizeof(char *));
	while( )
}