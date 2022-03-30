/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:02:23 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 16:28:57 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_move(t_stack **a, t_stack **b, t_stack *best)
{
	while (best->score_a > 0 && best->score_b > 0)
	{
		rr(a, b, 1);
		--best->score_a;
		--best->score_b;
	}
	while (best->score_a > 0)
	{
		ra(a, 1);
		--best->score_a;
	}
	while (best->score_b > 0)
	{
		rb(b, 1);
		--best->score_b;
	}
}

void	rrr_move(t_stack **a, t_stack **b, t_stack *best)
{
	while (best->score_a_r > 0 && best->score_b_r > 0)
	{
		rrr(a, b, 1);
		--best->score_a_r;
		--best->score_b_r;
	}
	while (best->score_a_r > 0)
	{
		rra(a, 1);
		--best->score_a_r;
	}
	while (best->score_b_r > 0)
	{
		rrb(b, 1);
		--best->score_b_r;
	}
}
