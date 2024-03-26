/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:10:24 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 22:21:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*buffer;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	buffer = (char *)malloc(len + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(buffer + i) = f(i, *(s + i));
		i++;
	}
	*(buffer + i) = '\0';
	return (buffer);
}
