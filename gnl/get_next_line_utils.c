/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:03:55 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:43:20 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* Check for a newline character in buffer front start_index */
size_t	find_newline(char *buf, size_t start_index)
{
	while (buf[start_index])
	{
		if (buf[start_index] == '\n')
			return (start_index + 1);
		start_index++;
	}
	return (0);
}

/* Initialises res as an empty string */
int	init_res(char **res)
{
	*res = (char *)malloc(sizeof(char) * 1);
	if (!*res)
		return (0);
	(*res)[0] = '\0';
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
