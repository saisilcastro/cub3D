/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:13:14 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/03 19:03:10 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, const char *set)
{
	char		*str;
	const char	*end;

	str = NULL;
	end = s + ft_strlen(s);
	while (*s)
	{
		if (!ft_strchr(set, *s))
			break ;
		s++;
	}
	while (end != s)
	{
		if (!ft_strchr(set, *(end - 1)))
			break ;
		end--;
	}
	if (end - s + 1 > 0)
		str = (char *)malloc((end - s + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if ((end - s + 1) <= 0)
		return (ft_strdup(""));
	ft_strlcpy(str, s, end - s + 1);
	return (str);
}
