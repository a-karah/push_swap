/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:54:13 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 16:28:16 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack **head, int flag)
{
	t_stack	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		ft_stackadd_back(head, tmp);
		if (flag)
			ft_printf("rb\n");
	}
}

void	rrb(t_stack **head, int flag)
{
	t_stack	*tmp;

	if (*head && (*head)->next)
	{
		tmp = ft_stacklast(*head);
		ft_stackbeforelast(*head)->next = NULL;
		ft_stackadd_front(head, tmp);
		if (flag)
			ft_printf("rrb\n");
	}
}

void	pb(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_stackadd_front(b, tmp);
		if (flag)
			ft_printf("pb\n");
	}
}

void	sb(t_stack **head, int flag)
{
	t_stack	*tmp;

	tmp = (*head)->next;
	if (*head && (*head)->next)
	{
		(*head)->next = (*head)->next->next;
		tmp->next = *head;
		*head = tmp;
		if (flag)
			ft_printf("sb\n");
	}
}
