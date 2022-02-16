/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:35 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:15:38 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_stack(t_stack **a, t_stack **b, int numbers)
{
	t_stack	*tmp;

	tmp = (*a)->next;
	if (numbers == 2)
	{
		if ((*a)->d_nbr > tmp->d_nbr)
			execute_s(a, 'a');
	}
	else if (numbers == 3)
		sort_3_stack(a);
	else if (numbers == 4)
	{
		sort_4_stack(a, b, 1);
		sort_3_stack(a);
		execute_p(a, b, 'a');
	}
	else if (numbers == 5)
		sort_5_stack(a, b);
}

void	sort_3_stack(t_stack **a)
{
	int	x;
	int	y;

	x = (*a)->next->d_nbr;
	y = (*a)->next->next->d_nbr;
	if ((*a)->d_nbr < x && (*a)->d_nbr < y && x > y)
	{
		execute_rr(a, 'a');
		execute_s(a, 'a');
	}	
	else if ((*a)->d_nbr > x && (*a)->d_nbr < y && x < y)
		execute_s(a, 'a');
	else if ((*a)->d_nbr < x && (*a)->d_nbr > y && x > y)
		execute_rr(a, 'a');
	else if ((*a)->d_nbr > x && x > y)
	{
		execute_r(a, 'a');
		execute_s(a, 'a');
	}
	else if ((*a)->d_nbr > x && (*a)->d_nbr > y && y > x)
		execute_r(a, 'a');
	return ;
}

void	sort_4_stack(t_stack **a, t_stack **b, int search)
{
	int		numbers;
	int		i;
	t_stack	*tmp;

	tmp = *a;
	numbers = 0;
	while (tmp)
	{
		numbers++;
		tmp = tmp->next;
	}
	i = 1;
	tmp = *a;
	while (tmp)
	{
		if (tmp->d_nbr == search)
			break ;
		i++;
		tmp = tmp->next;
	}
	help_4_stack(a, b, i, numbers);
}

void	help_4_stack(t_stack **a, t_stack **b, int i, int numbers)
{
	if (i == 2)
		execute_s(a, 'a');
	else if (i == 3)
	{
		execute_r(a, 'a');
		execute_r(a, 'a');
	}
	else if (i == 4 && numbers == 4)
		execute_rr(a, 'a');
	else if (i == 4 && numbers == 5)
	{
		execute_rr(a, 'a');
		execute_rr(a, 'a');
	}
	else if (i == 5)
		execute_rr(a, 'a');
	execute_p(a, b, 'b');
}

void	sort_5_stack(t_stack **a, t_stack **b)
{
	sort_4_stack(a, b, 1);
	sort_4_stack(a, b, 2);
	sort_3_stack(a);
	execute_p(a, b, 'a');
	execute_p(a, b, 'a');
}
