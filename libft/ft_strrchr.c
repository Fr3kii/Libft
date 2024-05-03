/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:55:16 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:41:30 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	while (len > 0)
	{
		if (*s == ((unsigned char)c))
			return ((char *)s);
		len--;
		s--;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
