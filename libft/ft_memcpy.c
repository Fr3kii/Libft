/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:50:10 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:40:25 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*pt;
	unsigned char			*s;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	pt = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n > 0)
	{
		pt[i] = s[i];
		i++;
		n--;
	}
	return (pt);
}
