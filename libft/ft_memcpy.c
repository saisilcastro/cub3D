/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:32:33 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 14:42:32 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*c_src;
	unsigned char	*c_dest;

	c_src = (unsigned char *)src;
	c_dest = (unsigned char *)dest;
	while (n--)
		*c_dest++ = *c_src++;
	return (dest);
}
