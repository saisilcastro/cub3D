/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:25:51 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 15:46:13 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	if (n > 0)
	{
		i = n - 1;
		if (len < n)
			i = len;
		ft_memcpy(dest, src, i);
		*(dest + i) = '\0';
	}
	return (len);
}
