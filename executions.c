/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:11 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:15:13 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *one, t_stack *two)
{
	int		x;
	char	*y;

	x = one->d_nbr;
	one->d_nbr = two->d_nbr;
	two->d_nbr = x;
	y = one->b_nbr;
	one->b_nbr = two->b_nbr;
	two->b_nbr = y;
}

void	execute_s(t_stack **stack, char c)
{
	t_stack	*tmp1;

	tmp1 = (*stack)->next;
	swap((*stack), tmp1);
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	execute_r(t_stack **stack, char c)
{
	t_stack	*tmp1;

	tmp1 = *stack;
	*stack = tmp1->next;
	tmp1->next = NULL;
	stack_add_back(stack, tmp1);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	execute_rr(t_stack **stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *stack;
	while (tmp1->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	stack_add_front(stack, tmp1);
	tmp2->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

void	execute_p(t_stack **a, t_stack **b, char c)
{
	t_stack	*new;

	new = NULL;
	if (c == 'b')
	{
		new = new_node((*a)->d_nbr, (*a)->b_nbr);
		stack_add_front(b, new);
		new = *a;
		*a = new->next;
		free(new);
		write(1, "pb\n", 3);
	}
	if (c == 'a')
	{
		new = new_node((*b)->d_nbr, (*b)->b_nbr);
		stack_add_front(a, new);
		new = *b;
		*b = new->next;
		free(new);
		write(1, "pa\n", 3);
	}
}
