/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:48:08 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 21:38:51 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	const char	*b;
	const char	*l;
	size_t		i;

	if (!*little)
		return ((char *)big);
	while (*big && n > 0)
	{
		if (*big == *little)
		{
			b = big;
			l = little;
			i = n;
			while (*b && *l && *b == *l && i-- > 0)
			{
				b++;
				l++;
			}
			if (!*l)
				return ((char *)big);
		}
		big++;
		n--;
	}
	return (NULL);
}
