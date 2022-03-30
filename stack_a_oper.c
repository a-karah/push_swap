/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_oper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:52:51 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 16:27:59 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **head, int flag)
{
	t_stack	*tmp;

	if (*head && (*head)->next)
	{
		tmp = *head;
		*head = (*head)->next;
		tmp->next = NULL;
		ft_stackadd_back(head, tmp);
		if (flag)
			ft_printf("ra\n");
	}
}

void	rra(t_stack **head, int flag)
{
	t_stack	*tmp;

	if (*head && (*head)->next)
	{
		tmp = ft_stacklast(*head);
		ft_stackbeforelast(*head)->next = NULL;
		ft_stackadd_front(head, tmp);
		if (flag)
			ft_printf("rra\n");
	}
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_stackadd_front(a, tmp);
		if (flag)
			ft_printf("pa\n");
	}
}

void	sa(t_stack **head, int flag)
{
	t_stack	*tmp;

	tmp = (*head)->next;
	if (*head && (*head)->next)
	{
		(*head)->next = (*head)->next->next;
		tmp->next = *head;
		*head = tmp;
		if (flag)
			ft_printf("sa\n");
	}
}
