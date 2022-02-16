/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:33 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:15:34 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_stack(t_stack **a, t_stack **b, int numbers)
{
	int		i;
	int		largest_index;
	int		iterations;

	largest_index = find_big_nbr(*a, numbers);
	i = 32;
	while (largest_index >= 0)
	{
		iterations = numbers;
		while (iterations > 0)
		{
			if (((*a)->b_nbr)[i] == '0')
				execute_p(a, b, 'b');
			else if (((*a)->b_nbr)[i] == '1')
				execute_r(a, 'a');
			iterations--;
		}
		while (*b)
			execute_p(a, b, 'a');
		largest_index--;
		i--;
	}
}

int	find_big_nbr(t_stack *a, int largest_nbr)
{
	int	i;

	while (a)
	{
		if (a->d_nbr == largest_nbr)
			break ;
		a = a->next;
	}
	i = 0;
	while (i < 32)
	{
		if ((a->b_nbr)[i] == '1')
			break ;
		i++;
	}
	return (32 - i);
}
