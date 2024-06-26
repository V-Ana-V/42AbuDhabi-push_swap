/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:24:41 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:33:25 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(t_arr *result)
{
	int	i;

	i = 0;
	if (result == NULL || result->arr == NULL)
		return ;
	else
	{
		while (i < result->len)
		{
			free((result->arr)[i]);
			i++;
		}
		free(result->arr);
		result->arr = NULL;
	}
}

static t_arr	args_append(t_arr *result, t_arr *av_args)
{
	char	**temp;
	int		i;

	i = 0;
	if (result->arr == NULL)
		return (*av_args);
	if (av_args->arr == NULL)
		return (*result);
	temp = (char **)malloc((result->len + av_args->len) * sizeof(char *));
	if (!temp)
		return (free_array(result), free_array(av_args),
			(t_arr){.arr = NULL, .len = 0, .malloc_fail = true});
	while (i < result->len)
	{
		temp[i] = result->arr[i];
		i++;
	}
	while (i < result->len + av_args->len)
	{
		temp[i] = (av_args->arr)[i - result->len];
		i++;
	}
	return (free(result->arr), result->arr = NULL, free(av_args->arr),
		av_args->arr = NULL, (t_arr){.arr = temp,
		.len = (result->len + av_args->len), .malloc_fail = false});
}

t_arr	make_args(int ac, char **av)
{
	int		i;
	t_arr	av_args;
	t_arr	result;

	result.arr = NULL;
	result.len = 0;
	result.malloc_fail = false;
	if (ac == 1)
		return ((t_arr){.arr = NULL, .len = 0, .malloc_fail = false});
	i = 1;
	while (av[i] != NULL)
	{
		av_args = parse_one(av[i]);
		if (av_args.malloc_fail == true)
			free_and_exit_args_only(&result);
		result = args_append(&result, &av_args);
		if (result.malloc_fail == true)
			free_and_exit_args_only(&result);
		i++;
	}
	return (result);
}
