/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:02:09 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 16:29:06 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	score_b(t_stack *b)
{
	int	size;
	int	i;

	i = 0;
	size = ft_stacksize(b);
	while (b)
	{
		b->score_b = i;
		b->score_b_r = size - i;
		b = b->next;
		++i;
	}
}

static void	score_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		size;
	int		prev;
	int		i;

	size = ft_stacksize(a);
	tmp = a;
	while (b)
	{
		i = 0;
		a = tmp;
		prev = ft_stacklast(a)->value;
		while (a)
		{
			if (prev < b->value && a->value > b->value)
			{
				b->score_a = i;
				b->score_a_r = size - i;
			}
			prev = a->value;
			a = a->next;
			++i;
		}
		b = b->next;
	}
}

static t_stack	*find_minmove(t_stack *head)
{
	t_stack	*best;
	int		best_score;

	best = head;
	best_score = total_score(head);
	while (head)
	{
		if (total_score(head) <= best_score
			|| (total_score(head) == best_score
				&& head->idx >= best->idx))
		{
			best_score = total_score(head);
			best = head;
		}
		head = head->next;
	}
	return (best);
}

static void	domove(t_stack **a, t_stack **b, t_stack *best)
{
	if (best->opflag & RR)
		rr_move(a, b, best);
	else if (best->opflag & RRR)
		rrr_move(a, b, best);
	else if (best->opflag & RB_RRA)
	{
		while (best->score_b-- > 0)
			rb(b, 1);
		while (best->score_a_r-- > 0)
			rra(a, 1);
	}
	else if (best->opflag & RRB_RA)
	{
		while (best->score_b_r-- > 0)
			rrb(b, 1);
		while (best->score_a-- > 0)
			ra(a, 1);
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;

	score_b(*b);
	score_a(*a, *b);
	best = find_minmove(*b);
	domove(a, b, best);
	pa(a, b, 1);
}
