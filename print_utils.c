/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:54:00 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/05 19:54:01 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printstack(t_stack *head)
{
	while (head)
	{
		ft_printf("%d->", head->value);
		head = head->next;
	}
	ft_printf("(null)\n");
}
