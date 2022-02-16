/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:40 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:15:46 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while ((*lst))
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->b_nbr);
		free(tmp);
	}
	*lst = NULL;
}

int	create_stack(char *str, t_stack **a, t_stack **new)
{
	int		d_nbr;
	char	*b_nbr;

	if (!input_correct(str))
		return (0);
	d_nbr = ft_atoi(str);
	b_nbr = ft_atoi_binary_str(d_nbr);
	*new = new_node(d_nbr, b_nbr);
	if (!(*new))
		return (0);
	if (!stack_add_back(a, *new))
	{
		free_stack(new);
		return (0);
	}
	return (1);
}

t_stack	*new_node(int dec_nbr, char *bin_nbr)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->d_nbr = dec_nbr;
	new_stack->b_nbr = bin_nbr;
	new_stack->next = NULL;
	return (new_stack);
}

int	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!(*stack))
	{
		*stack = new;
		return (1);
	}
	while (tmp->next != NULL)
	{
		if (tmp->d_nbr == new->d_nbr)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->d_nbr == new->d_nbr)
		return (0);
	tmp->next = new;
	return (1);
}

int	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!(*stack))
	{	
		*stack = new;
		return (1);
	}
	new->next = *stack;
	*stack = new;
	return (1);
}
