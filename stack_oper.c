/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:54:09 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 16:35:03 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag)
		ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		ft_printf("rrr\n");
}
