/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 03:55:35 by mister-code       #+#    #+#             */
/*   Updated: 2023/12/28 12:21:43 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <level.h>
#include <file_of.h>
#include <string.h>
#include <stdlib.h>

static inline char	*buffer_push(char *file, int *max)
{
	int		i;
	char	*buffer;

	*max = file_size(file);
	if (!max)
		return (NULL);
	buffer = malloc((*max + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = -1;
	while (++i < *max)
		*(buffer + i) = '\0';
	return (buffer);
}

static inline void	texture_get(t_level *set, char *buffer)
{
	char	temp[4][65535];
	int		n;
	int		i;

	n = 0;
	while (*buffer && n < 4)
	{
		if ((*buffer == 'N' && *(buffer + 1) == 'O')
			|| (*buffer == 'S' && *(buffer + 1) == 'O')
			|| (*buffer == 'W' && *(buffer + 1) == 'E')
			|| (*buffer == 'E' && *(buffer + 1) == 'A'))
		{
			buffer = buffer + 3;
			i = -1;
			while (*buffer && *buffer != '\n' && *buffer != ' ')
				*(*(temp + n) + ++i) = *buffer++;
			*(*(temp + n) + ++i) = '\0';
			*(set->texture + n) = *(temp + n);
		}
		if (*buffer == '\n')
			n++;
		buffer++;
	}
}

static char	*color_get(t_level *set, char *buffer, int *n)
{
	int		i;
	int		j;
	char	number[65535];

	i = -1;
	j = 0;
	while (*buffer && *buffer != ' ' && *buffer != '\n')
	{
		*(number + ++i) = *buffer++;
		if (*buffer == ',')
		{
			buffer++;
			*(number + ++i) = '\0';
			if (j == 0)
				set->color[*n].r = atoi(number);
			else if (j == 1)
				set->color[*n].g = atoi(number);
			i = -1;
			j++;
		}
	}
	*(number + ++i) = '\0';
	if (j == 2)
		set->color[*n].b = atoi(number);
	return (buffer);
}

static inline char	*color_search(t_level *set, char *buffer)
{
	int		n;

	n = 0;
	while (*buffer && n < 2)
	{
		if (*buffer == 'F' || *buffer == 'C')
		{
			buffer = color_get(set, buffer + 2, &n);
			if (*buffer == '\n')
				n++;
		}
		buffer++;
	}
	if (*buffer == '\n')
		buffer++;
	return (buffer);
}

t_status	level_load(t_level *set, char *file)
{
	int		fd;
	char	*buffer;
	char	*pos;
	int		max;

	max = 0;
	if (!file)
		return (Off);
	buffer = buffer_push(file, &max);
	if (!buffer)
		return (Off);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (Off);
	read(fd, buffer, max);
	pos = buffer;
	texture_get(set, pos);
	pos = color_search(set, pos);
	set->data = malloc((pos - buffer + 1) * sizeof(int));
	max = -1;
	while (*pos && set->data)
		*(set->data + ++max) = *pos++;
	*(set->data + ++max) = 0;
	close(fd);
	free(buffer);
	return (On);
}
