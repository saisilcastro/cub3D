/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 05:08:07 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/27 14:16:50 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <file_of.h>
#include <stdio.h>

int	file_size(char *file)
{
	int		size;
	char	symbol;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	size = 0;
	while (read(fd, &symbol, 1) && symbol != EOF)
		size++;
	close(fd);
	return (size);
}
