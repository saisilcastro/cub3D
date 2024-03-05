/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:09:09 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 19:54:41 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int index, char *str))
{
	char			*buffer;
	unsigned int	i;

	i = 0;
	buffer = s;
	while (*(buffer + i))
	{
		f(i, &*(buffer + i));
		i++;
	}
}
