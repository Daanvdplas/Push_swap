/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:30 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:15:31 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	char			*b_nbr;
	int				d_nbr;
	struct s_stack	*next;
}	t_stack;

// FUNCTIONS:

// Input:
int		input_handler(int argc, char *argv[]);
int		input_correct(char *str);

// Stack:
t_stack	*new_node(int dec_nbr, char *bin_nbr);
int		stack_add_back(t_stack **stack, t_stack *new);
int		stack_add_front(t_stack **stack, t_stack *new);
int		create_stack(char *str, t_stack **a, t_stack **new);
void	free_stack(t_stack **lst);

// Letsgo:

int		letsgo(t_stack **a, int nbrs);
int		index_conv_help(t_stack *a, int number);
int		index_conv(t_stack **a, int counter, t_stack **new_stack);
int		ft_atoi_help(const char *str);

// Small stack:

void	sort_small_stack(t_stack **a, t_stack **b, int nbrs);
void	sort_3_stack(t_stack **a);
void	sort_4_stack(t_stack **a, t_stack **b, int search);
void	sort_5_stack(t_stack **a, t_stack **b);
void	help_4_stack(t_stack **a, t_stack **b, int i, int numbers);
void	help_5_stack(t_stack **a);

// Big stack:

void	sort_big_stack(t_stack **a, t_stack **b, int numbers);
int		find_big_nbr(t_stack *a, int largest_nbr);

// Executions:

void	swap(t_stack *one, t_stack *two);
void	execute_s(t_stack **stack, char c);
void	execute_r(t_stack **stack, char c);
void	execute_rr(t_stack **stack, char c);
void	execute_p(t_stack **a, t_stack **b, char c);

#endif