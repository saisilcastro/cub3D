/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:51:41 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/01 21:02:43 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	number_len(long n, int base)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

static char	*number_allocate(int n, int *len, int *negative)
{
	char	*buffer;
	long	number;

	number = n;
	buffer = NULL;
	*len = number_len(n, 10);
	if (*len == 0)
	{
		*len = 0;
		buffer = (char *)malloc(2 * sizeof(char));
		*(buffer + 0) = 48;
		*(buffer + 1) = '\0';
		return (buffer);
	}
	if (n < 0)
	{
		number = -number;
		*len += 1;
		*negative = 1;
	}
	buffer = (char *)malloc(*len + 1 * sizeof(char));
	if (n < 0)
		*(buffer + 0) = '-';
	*(buffer + *len) = '\0';
	return (buffer);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;
	int		begin;
	long	iter;
	int		negative;

	begin = 0;
	iter = n;
	len = 0;
	negative = 0;
	number = number_allocate(n, &len, &negative);
	if (negative == 1)
	{
		begin = 1;
		iter = -iter;
	}
	while (--len >= begin)
	{
		*(number + len) = (char)(iter % 10) + 48;
		iter /= 10;
	}
	return (number);
}
