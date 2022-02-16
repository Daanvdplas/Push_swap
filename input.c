/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:15:16 by dvan-der          #+#    #+#             */
/*   Updated: 2022/01/28 15:11:49 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_correct(char *str)
{
	int			i;
	int			j;
	static int	length;

	length = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		i++;
		j++;
	}
	if (i != length || !ft_atoi_help(str) || j == 0)
		return (0);
	return (1);
}

static int	checker_checker(t_stack **a, int nbrs)
{	
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->d_nbr < tmp->next->d_nbr)
			tmp = tmp->next;
		else
			break ;
	}
	if (!tmp->next)
	{
		free_stack(a);
		return (1);
	}
	if (!letsgo(a, nbrs))
	{
		free_stack(a);
		return (0);
	}
	return (1);
}

static int	input_single(char *str, t_stack *a, t_stack *new)
{
	char	**split_str;
	int		counter;
	int		i;

	split_str = ft_split(str, ' ');
	counter = 0;
	while (split_str[counter])
		counter++;
	i = 0;
	while (i < counter)
	{
		if (!create_stack(split_str[i], &a, &new))
		{
			ft_free_split(split_str);
			free_stack(&a);
			return (0);
		}
		i++;
	}
	ft_free_split(split_str);
	if (!checker_checker(&a, counter))
		return (0);
	return (1);
}

static int	input_multiple(int argc, char *argv[], t_stack *a, t_stack *new)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!create_stack(argv[i], &a, &new))
		{
			free_stack(&a);
			return (0);
		}
		i++;
	}
	if (!checker_checker(&a, argc - 1))
		return (0);
	return (1);
}

int	input_handler(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*new;

	a = NULL;
	new = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		if (!input_single(argv[1], a, new))
			return (0);
	}
	else if (argc > 2)
	{
		if (!input_multiple(argc, argv, a, new))
			return (0);
	}
	return (1);
}
