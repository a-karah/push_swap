/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:01:38 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/13 15:05:45 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	give_idx(t_stack *head, t_arr *arr)
{
	int	i;

	ft_qsort(arr->av_ints, 0, arr->len - 1);
	arr->min = arr->av_ints[0];
	arr->med = arr->av_ints[arr->len / 2];
	arr->max = arr->av_ints[arr->len - 1];
	while (head)
	{
		i = 0;
		while (arr->av_ints[i] != head->value)
			++i;
		head->idx = i;
		head = head->next;
	}
}

static void	triple_sort(t_stack **head)
{
	int	size;
	int	x;
	int	y;
	int	z;

	size = ft_stacksize(*head);
	if (size == 3)
	{
		x = (*head)->value;
		y = (*head)->next->value;
		z = (*head)->next->next->value;
		if (y > z && y > x && z > x)
			sa(head, 1);
		if (z > x && z > y && x > y)
			sa(head, 1);
		if (x > z && x > y && y > z)
			sa(head, 1);
	}
}

int	total_score(t_stack *head)
{
	int	max_rr;
	int	max_rrr;
	int	best;

	head->opflag = 0;
	max_rr = ft_max_int(head->score_a, head->score_b);
	max_rrr = ft_max_int(head->score_a_r, head->score_b_r);
	best = ft_min_int(max_rr, max_rrr);
	if (max_rr == best)
		head->opflag |= RR;
	else
		head->opflag |= RRR;
	if (head->score_a_r + head->score_b < best)
	{
		best = head->score_a_r + head->score_b;
		head->opflag = (head->opflag & 0) | RB_RRA;
	}
	else if (head->score_a + head->score_b_r < best)
	{
		best = head->score_a + head->score_b_r;
		head->opflag = (head->opflag & 0) | RRB_RA;
	}
	return (best);
}

t_stack	*a_to_b(t_stack **head, t_arr *arr)
{
	t_stack	*b;
	int		size;

	b = NULL;
	size = ft_stacksize(*head);
	give_idx(*head, arr);
	while (size > 3)
	{
		if ((*head)->value == arr->min || (*head)->value == arr->med
			|| (*head)->value == arr->max)
			ra(head, 1);
		else
		{
			pb(head, &b, 1);
			--size;
		}
	}
	triple_sort(head);
	return (b);
}
