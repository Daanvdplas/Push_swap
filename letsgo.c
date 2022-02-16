/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letsgo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:22 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:19:50 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	letsgo(t_stack **a, int nbrs)
{
	t_stack	*new_stack;
	t_stack	*b;

	new_stack = NULL;
	if (!index_conv(a, nbrs, &new_stack))
		return (0);
	a = &new_stack;
	b = NULL;
	if (nbrs < 6 && nbrs > 1)
		sort_small_stack(a, &b, nbrs);
	else if (nbrs > 5)
		sort_big_stack(a, &b, nbrs);
	free_stack(a);
	free_stack(&b);
	return (1);
}

int	index_conv_help(t_stack *a, int number)
{
	int	i;

	i = 0;
	while (a)
	{
		if (number > a->d_nbr)
			i++;
		a = a->next;
	}
	return (i + 1);
}

int	index_conv(t_stack **a, int counter, t_stack **new_stack)
{
	t_stack	*tmp;
	t_stack	*new;
	int		x;
	char	*str;

	tmp = *a;
	new = NULL;
	while (0 < counter)
	{
		x = index_conv_help(*a, tmp->d_nbr);
		str = ft_itoa(x);
		if (!create_stack(str, new_stack, &new))
		{
			free_stack(new_stack);
			return (0);
		}
		tmp = tmp->next;
		counter--;
		free(str);
	}
	free_stack(a);
	return (1);
}

int	ft_atoi_help(const char *str)
{
	long long	nbr;
	int			p_n;
	size_t		i;

	p_n = 1;
	nbr = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
	{
		p_n = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	nbr *= p_n;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}
