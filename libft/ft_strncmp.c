/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:49:18 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/30 14:30:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i) && i < n)
	{
		if (*(s1 + i) != *(s2 + i))
			break ;
		i++;
	}
	if (n == i)
		return (0);
	return ((int)(unsigned char)*(s1 + i) - (unsigned char)*(s2 + i));
}
