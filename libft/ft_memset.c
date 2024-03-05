/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:25:55 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:56:29 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			pos;
	unsigned char	*buffer;

	pos = 0;
	buffer = (unsigned char *)str;
	while (pos < n)
	{
		*(buffer + pos) = c;
		pos++;
	}
	return (buffer);
}
