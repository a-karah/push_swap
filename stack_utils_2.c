/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:09:58 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 14:10:00 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		++i;
	}
	return (i);
}

void	ft_stackadd_back(t_stack **head, t_stack *new)
{
	t_stack	*tmp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	ft_stackadd_front(t_stack **head, t_stack *new)
{
	new->next = *head;
	*head = new;
}

void	ft_stackclear(t_stack **head)
{
	t_stack	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
