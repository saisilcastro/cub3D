/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:58:46 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 22:05:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	size_t	s_len;
	char	*sub;

	s_len = ft_strlen(s);
	if (!s || start >= s_len)
	{
		sub = (char *)malloc(1);
		*(sub + 0) = '\0';
		return (sub);
	}		
	if (start + len > s_len)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	*(sub + len) = '\0';
	return (sub);
}
