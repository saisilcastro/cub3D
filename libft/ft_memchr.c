/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:34:47 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 11:49:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*buffer;
	size_t				i;

	buffer = str;
	i = 0;
	while (i < n)
	{
		if (*(buffer + i) == (unsigned char)c)
			return ((void *)&*(buffer + i));
		i++;
	}
	return (NULL);
}
