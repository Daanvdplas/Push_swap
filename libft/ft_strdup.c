/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-der <dvan-der@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:17:35 by dvan-der          #+#    #+#             */
/*   Updated: 2021/12/15 08:17:36 by dvan-der         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	str[len] = '\0';
	return (str);
}
