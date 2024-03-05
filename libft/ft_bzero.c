/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:26:39 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:44:32 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*buffer;
	size_t			pos;

	buffer = str;
	pos = 0;
	while (pos < n)
	{
		*(buffer + pos) = '\0';
		pos++;
	}
}
