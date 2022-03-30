/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:54:04 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/13 15:35:34 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	last_sort(t_stack **head, t_arr *arr)
{
	t_stack	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = *head;
	size = ft_stacksize(*head);
	while (tmp && tmp->value != arr->min)
	{
		tmp = tmp->next;
		++i;
	}
	if (i <= size - i)
		while (i-- > 0)
			ra(head, 1);
	else
		while (i++ < size)
			rra(head, 1);
}

void	small_select(t_stack **a, t_stack **b, t_stack *last)
{
	if (((*a)->value < last->value)
		&& ((*a)->value < (*a)->next->value))
		pb(a, b, 1);
	else if ((*a)->value < last->value)
		sa(a, 1);
	else if ((*a)->next->value > last->value)
		rra(a, 1);
	else
		ra(a, 1);
}

void	small_sort(t_stack **head)
{
	t_stack	*last;
	t_stack	*b;

	b = NULL;
	last = ft_stacklast(*head);
	while (is_sorted(*head))
	{
		while (*head && is_sorted(*head))
		{
			small_select(head, &b, last);
			last = ft_stacklast(*head);
		}
		while (b)
		{
			if (b->next && b->value < b->next->value)
				sb(&b, 1);
			pa(head, &b, 1);
		}
	}
}

t_stack	*sort_stack(t_stack **head, t_arr *arr)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(*head))
	{
		if (ft_stacksize(*head) > 3 && ft_stacksize(*head) < 10)
			small_sort(head);
		else
		{
			b = a_to_b(head, arr);
			while (b)
				b_to_a(head, &b);
			last_sort(head, arr);
		}
	}
	return (b);
}
