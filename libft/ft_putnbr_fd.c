/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:20:49 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:13:53 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	multiply;
	char	number;

	multiply = 1;
	if (n > -10 && n < 0)
		write(fd, "-", 1);
	while (n <= -10 || n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	if (n < 0)
		multiply = -1;
	number = (n * multiply) + 48;
	write(fd, &number, 1);
}
