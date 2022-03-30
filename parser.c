/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:03:17 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 16:58:01 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*parser(int ac, char *av[])
{
	char	*av_buf;
	char	*tmp;
	int		i;

	i = 1;
	av_buf = ft_strdup("");
	while (i < ac)
	{
		if (ft_strncmp(av[i], "", 10) == 0)
		{
			free(av_buf);
			handle_error();
		}
		tmp = av_buf;
		av_buf = ft_strjoin(av_buf, av[i]);
		free(tmp);
		tmp = av_buf;
		av_buf = ft_strjoin(av_buf, " ");
		free(tmp);
		++i;
	}
	return (av_buf);
}
