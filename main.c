/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:57:36 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 15:50:48 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	*av_buf;
	t_arr	*arr;
	t_stack	*a;

	if (ac == 1)
		return (0);
	av_buf = parser(ac, av);
	arr = (t_arr *)malloc(sizeof(t_arr));
	args_checker(av_buf, arr);
	a = ft_addtostack(arr);
	sort_stack(&a, arr);
	free_list(a);
	free_arr(arr);
	free(av_buf);
	return (0);
}
