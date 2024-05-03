/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:14:57 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:40:19 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_memcmp( const void *s1, const void *s2, size_t size )
{
	unsigned int	delta;

	if (size == 0)
		return (0);
	while (size > 0)
	{
		delta = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (delta != 0)
			return (delta);
		size--;
	}
	return (delta);
}
