/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:16:15 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:16:16 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	int		*ptr;

	ptr = malloc(num * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, num * size);
	return (ptr);
}
