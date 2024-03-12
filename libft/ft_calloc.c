/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:33:22 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/12 11:31:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			j;

	i = len * size;
	if (i != 0 && i / size != len)
		return (NULL);
	ptr = (unsigned char *)malloc(i);
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < i)
	{
		*(ptr + j) = '\0';
		j++;
	}
	return ((void *)ptr);
}
