/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:03:22 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 14:09:56 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int nbr)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nbr;
	new->idx = -1;
	new->score_a = -1;
	new->score_a_r = -1;
	new->score_b = -1;
	new->score_b_r = -1;
	new->next = NULL;
	return (new);
}

t_stack	*ft_addtostack(t_arr *arr)
{
	t_stack	*head;
	int		i;

	i = 0;
	head = NULL;
	while (i < arr->len)
	{
		ft_stackadd_back(&head, ft_stacknew(arr->av_ints[i]));
		++i;
	}
	return (head);
}

t_stack	*ft_stacklast(t_stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_stack	*ft_stackbeforelast(t_stack *head)
{
	while (head->next->next)
		head = head->next;
	return (head);
}
