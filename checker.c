/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:13:12 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 17:34:56 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a(t_stack *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	do_cmd(t_stack **a, t_stack **b, char *s)
{
	if (ft_strncmp(s, "ra\n", 5) == 0)
		ra(a, 0);
	else if (ft_strncmp(s, "rb\n", 5) == 0)
		rb(b, 0);
	else if (ft_strncmp(s, "rra\n", 5) == 0)
		rra(a, 0);
	else if (ft_strncmp(s, "rrb\n", 5) == 0)
		rrb(b, 0);
	else if (ft_strncmp(s, "sa\n", 5) == 0)
		sa(a, 0);
	else if (ft_strncmp(s, "sb\n", 5) == 0)
		sb(b, 0);
	else if (ft_strncmp(s, "pa\n", 5) == 0)
		pa(a, b, 0);
	else if (ft_strncmp(s, "pb\n", 5) == 0)
		pb(a, b, 0);
	else if (ft_strncmp(s, "rr\n", 5) == 0)
		rr(a, b, 0);
	else if (ft_strncmp(s, "rrr\n", 5) == 0)
		rrr(a, b, 0);
	else if (ft_strncmp(s, "ss\n", 5) == 0)
		ss(a, b, 0);
	else
		return (0);
	return (1);
}

void	checker(t_stack **a)
{
	t_stack	*b;
	char	*s;

	b = NULL;
	s = get_next_line(0);
	while (s)
	{
		if (!do_cmd(a, &b, s))
		{
			free_list(*a);
			free(s);
			handle_error();
		}
		free(s);
		s = get_next_line(0);
	}
	if (check_a(*a) && b == NULL)
		ft_putendl_fd("OK", STDOUT);
	else
		ft_putendl_fd("KO", STDOUT);
	free_list(*a);
	free_list(b);
}

int	main(int ac, char *av[])
{
	char	*av_buf;
	t_arr	*arr;
	t_stack	*a;

	if (ac == 1)
		return (0);
	av_buf = parser(ac, av);
	arr = (t_arr *)malloc(sizeof(t_arr));
	args_checker(av_buf, arr);
	a = ft_addtostack(arr);
	checker(&a);
	free_arr(arr);
	free(av_buf);
	return (0);
}
