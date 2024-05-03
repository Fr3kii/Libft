/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:24:44 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:40:47 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static unsigned int	len_word(const char *s2, char c, int i)
{
	unsigned int	len;

	len = 0;
	while (s2[i] != '\0' && s2[i] != c)
	{
		len++;
		s2++;
	}
	return (len);
}

static char	**use_free(char **dest, unsigned int a)
{
	while (a > 0)
	{
		a--;
		free((void *)dest[a]);
	}
	free(dest);
	return (0);
}

static char	**affect(char **dest, char const *s, char c, unsigned int i)
{
	unsigned int	index;
	unsigned int	a; 
	unsigned int	b; 

	index = 0;
	a = 0;
	while (s[index] != '\0' && a < i)
	{
		b = 0;
		while (s[index] == c)
			index++;
		dest[a] = (char *)malloc(sizeof(char) * len_word(s, c, index) + 1);
		if (!dest[a])
			return (use_free(dest, a));
		while (s[index] != '\0' && s[index] != c)
			dest[a][b++] = s[index++];
		dest[a][b] = '\0';
		a++;
	}
	dest[a] = 0;
	return (dest);
}

static unsigned int	number_word(char const *s1, char c)
{
	unsigned int	id;
	unsigned int	word;

	id = 0;
	word = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			word = 0;
		else if (word == 0)
		{
			word = 1;
			id++;
		}
		s1++;
	}
	return (id);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**dest;

	if (!s)
		return (0);
	i = number_word(s, c);
	dest = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (0);
	return (affect(dest, s, c, i));
}
