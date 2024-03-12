/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:35:54 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 20:38:22 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	size_t	pos;
	char	*dest;

	len = ft_strlen(src);
	pos = 0;
	dest = (char *)malloc((len + 1) * sizeof(char));
	while (*(src + pos))
	{
		*(dest + pos) = *(src + pos);
		pos++;
	}
	*(dest + pos) = '\0';
	return (dest);
}
