/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:39:13 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:41:11 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	i;
	size_t	j;
	size_t	size_src;

	size_src = 0;
	size_dest = 0;
	i = 0;
	while (src[size_src])
		size_src++;
	if (size == 0 && !dst)
		return (size_src + size_dest);
	while (dst[size_dest] && size_dest < size)
		size_dest++;
	if (size_dest == size)
		return (size_dest + size_src);
	j = size_dest;
	while (src[i] && j < size - 1)
	{
		dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (size_dest + size_src);
}
