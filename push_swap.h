/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarahan <akarahan@student.42istanbul.com. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:58:13 by akarahan          #+#    #+#             */
/*   Updated: 2022/03/11 17:13:48 by akarahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "./libft/includes/libft.h"

enum {
	RR = (1 << 0),
	RRR = (1 << 1),
	RB_RRA = (1 << 2),
	RRB_RA = (1 << 3),
};

typedef struct s_arr
{
	int	*av_ints;
	int	len;
	int	min;
	int	med;
	int	max;
}			t_arr;

typedef struct s_stack
{
	struct s_stack	*next;
	short			opflag;
	int				value;
	int				idx;
	int				score_a;
	int				score_a_r;
	int				score_b;
	int				score_b_r;
}			t_stack;

/* handle_error.c */
void	handle_error(void);

/* parser.c */
char	*parser(int ac, char *av[]);

/* args_checker.c */
int		check_isdig(char **av_list);
int		check_dup(char **av_list);
int		check_int(char **av_list, int *av_ints);
void	args_checker(char *av_buf, t_arr *arr);

/* stack_utils_1.c */
t_stack	*ft_stacknew(int nbr);
t_stack	*ft_addtostack(t_arr *arr);
t_stack	*ft_stacklast(t_stack *head);
t_stack	*ft_stackbeforelast(t_stack *head);

/* stack_utils_2.c */
int		ft_stacksize(t_stack *head);
void	ft_stackadd_back(t_stack **head, t_stack *new);
void	ft_stackadd_front(t_stack **head, t_stack *new);
void	ft_stackclear(t_stack **head);

/* sort.c */
t_stack	*sort_stack(t_stack **head, t_arr *arr);

/* print_utils.c */
void	ft_printstack(t_stack *head);

/* stack_oper.c */
void	ss(t_stack **a, t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);

/* stack_a_oper.c */
void	ra(t_stack **head, int flag);
void	rra(t_stack **head, int flag);
void	pa(t_stack **a, t_stack **b, int flag);
void	sa(t_stack **head, int flag);

/* stack_b_oper.c */
void	rb(t_stack **head, int flag);
void	rrb(t_stack **head, int flag);
void	pb(t_stack **a, t_stack **b, int flag);
void	sb(t_stack **head, int flag);

/* moves.c */
void	rr_move(t_stack **a, t_stack **b, t_stack *best);
void	rrr_move(t_stack **a, t_stack **b, t_stack *best);

/* a_to_b.c */
t_stack	*a_to_b(t_stack **head, t_arr *arr);
int		total_score(t_stack *head);

/* b_to_a.c */
void	b_to_a(t_stack **a, t_stack **b);

/* clean_vars.c */
void	free_list(t_stack *head);
void	free_arr(t_arr *arr);

#endif
