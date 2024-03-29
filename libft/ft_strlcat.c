/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:39:50 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/05 13:04:55 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*buffer;

	buffer = dest + ft_strlen(dest);
	while (*src && n--)
		*buffer++ = *src++;
	*buffer = '\0';
	return (dest);
}

size_t	ft_strlcat(char	*dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (dest_len >= n)
		return (n + src_len);
	ft_strncat(dest + dest_len, src, n - dest_len - 1);
	return (src_len + dest_len);
}
