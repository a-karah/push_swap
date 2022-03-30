/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:57:33 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 15:43:30 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_isdig(char **av_list)
{
	int	i;
	int	j;

	i = 0;
	while (av_list[i])
	{
		j = 0;
		while (av_list[i][j] == ' ')
			++j;
		if (av_list[i][j] == '-')
			++j;
		while (av_list[i][j])
		{
			if (!ft_isdigit(av_list[i][j]))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	check_dup(char **av_list)
{
	int	i;
	int	j;

	i = 0;
	while (av_list[i])
	{
		j = i + 1;
		while (av_list[j])
		{
			if (!ft_strncmp(av_list[i], av_list[j], 10))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	check_int(char **av_list, int *av_ints)
{
	long	nbr;
	int		i;

	i = 0;
	while (av_list[i])
	{
		nbr = ft_atol(av_list[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			return (0);
		av_ints[i] = nbr;
		++i;
	}
	return (1);
}

void	args_checker(char *av_buf, t_arr *arr)
{
	char	**av_list;
	int		error;
	int		i;

	av_list = ft_split(av_buf, ' ');
	error = 0;
	i = 0;
	while (av_list[i])
		++i;
	arr->len = i;
	arr->av_ints = (int *)malloc(sizeof(int) * i);
	if (!check_isdig(av_list) || !check_dup(av_list)
		|| !check_int(av_list, arr->av_ints))
		++error;
	while (i--)
		free(av_list[i]);
	free(av_list);
	if (error)
	{
		free_arr(arr);
		free(av_buf);
		handle_error();
	}
}
