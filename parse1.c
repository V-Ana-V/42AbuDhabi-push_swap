/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:46:23 by avelikan          #+#    #+#             */
/*   Updated: 2024/05/28 13:33:08 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ',');
}

static int	wordlen(char const *s, int i)
{
	int	l;

	l = 0;
	while (!is_separator(*(s + i + l)) && *(s + i + l))
		l++;
	return (l);
}

static char	**free_previous(char **res_start, char **result)
{
	char	**start;

	start = res_start;
	while (res_start != result)
	{
		free(*res_start);
		res_start++;
	}
	free(start);
	return (NULL);
}

static t_arr	create_arr(char const *s)
{
	int		w;
	int		i;
	t_arr	result;

	if (!s || !(*s))
		return ((t_arr){.arr = NULL, .len = 0, .malloc_fail = false});
	w = 0;
	i = 0;
	while (*(s + i))
	{
		if (!is_separator(*(s + i))
			&& (i == 0 || (i != 0 && is_separator(*(s + i - 1)))))
			w++;
		i++;
	}
	if (w == 0)
		return ((t_arr){.arr = NULL, .len = 0, .malloc_fail = false});
	result.arr = (char **)malloc(w * sizeof(char *));
	if (result.arr == NULL)
		return ((t_arr){.arr = NULL, .len = 0, .malloc_fail = true});
	result.len = w;
	result.malloc_fail = false;
	return (result);
}

t_arr	parse_one(char const *s)
{
	t_arr	result;
	int		i;
	char	**res_arr;

	result = create_arr(s);
	if (!result.arr && result.malloc_fail == true)
		return ((t_arr){.arr = NULL, .len = 0, .malloc_fail = true});
	else if (!result.arr)
		return ((t_arr){.arr = NULL, .len = 0, .malloc_fail = false});
	res_arr = result.arr;
	i = 0;
	while (*(s + i))
	{
		if (!is_separator(*(s + i))
			&& (i == 0 || (i != 0 && is_separator(*(s + i - 1)))))
		{
			*res_arr = ft_substr(s, i, wordlen(s, i));
			if (!(*res_arr))
				return ((t_arr){.arr = free_previous(result.arr, res_arr),
					.len = 0, .malloc_fail = true});
			(res_arr)++;
		}
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	*s;
// 	t_arr	arr;
// 	int		i;

// 	i = 0;
// 	s = "      h  \n\n\nnn   ";
// 	arr = parse_one(s);
// 	ft_printf("%d\n", arr.len);
// 	ft_printf("%p\n", arr.arr);
// 	ft_printf("%d\n", arr.malloc_fail);
// 	if (arr.arr == NULL)
// 		ft_printf("The array is NULL");
// 	while (i < arr.len)
// 	{
// 		ft_printf("%s\n", arr.arr[i]);
// 		i++;
// 	}
// 	return (0);
// }
