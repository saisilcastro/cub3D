/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:58 by lde-cast          #+#    #+#             */
/*   Updated: 2024/03/08 15:13:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static inline int	word_counter(char *s, int c)
{
	int		i;
	int		word;
	char	b_next_char;
	char	b_current_char;

	if (s == NULL)
		return (0);
	(void)c;
	word = 0;
	i = -1;
	while (s[++i] != '\0')
	{
		b_current_char = 0;
		b_next_char = 0;
		if (*(s + i) == c || *(s + i) == '\0')
			b_current_char = 1;
		if (*(s + i + 1) == c || *(s + i + 1) == '\0')
			b_next_char = 1;
		if (!b_current_char && b_next_char)
			word++;
	}
	return (word);
}

static inline int	begin_get(const char *s, char c, int *pos)
{
	int	begin;

	begin = 0;
	while (s && *(s + *pos))
	{
		while (*(s + *pos) == c)
			*pos += 1;
		if (!*(s + *pos))
			break ;
		while (*(s + *pos))
		{
			begin++;
			if (*(s + *pos + 1) == c || !*(s + *pos + 1))
			{
				*pos += 1;
				return (begin);
			}
			*pos += 1;
		}
		*pos += 1;
	}
	return (0);
}

void	copy_word(char **array, const char *s, int c, int word)
{
	int	i;
	int	j;
	int	pos;
	int	len;

	i = 0;
	j = 0;
	pos = 0;
	len = 0;
	while (i < word)
	{
		len = begin_get(s, c, &pos);
		*(array + i) = (char *)malloc((len + 1) * sizeof(char));
		j = -1;
		while (++j < len)
			*(*(array + i) + j) = *(s + pos - len + j);
		array[i][j] = '\0';
		i++;
	}
}

char	**ft_split(char *s, char c)
{
	int		word;
	char	**array;

	if (!s)
		return (NULL);
	word = word_counter(s, c);
	if (!word)
		return (NULL);
	array = (char **)malloc((word + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	copy_word(array, s, c, word);
	*(array + word) = NULL;
	return (array);
}
