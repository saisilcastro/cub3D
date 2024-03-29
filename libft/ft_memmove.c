/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:34:04 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 15:06:20 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*c_dest;
	unsigned const char	*c_src;
	size_t				i;

	c_dest = dest;
	c_src = src;
	if (c_dest <= c_src)
	{
		i = 0;
		while (i < n)
		{
			*(c_dest + i) = *(c_src + i);
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		*(c_dest + i - 1) = *(c_src + i - 1);
		i--;
	}
	return (dest);
}
