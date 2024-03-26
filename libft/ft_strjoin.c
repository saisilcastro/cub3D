/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:12:32 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 20:40:35 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		pos;
	char	*whole;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	whole = malloc((l1 + l2 + 1) * sizeof(char));
	if (!whole)
		return (NULL);
	pos = 0;
	while (*s1)
	{
		*(whole + pos) = *s1;
		s1++;
		pos++;
	}
	while (*s2)
	{
		*(whole + pos) = *s2;
		s2++;
		pos++;
	}
	*(whole + pos) = '\0';
	return (whole);
}
