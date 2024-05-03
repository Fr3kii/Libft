/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:18:16 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:40:31 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t						i;
	unsigned char				*pt;
	const unsigned char			*tmp;

	i = 0;
	pt = (unsigned char *)dest;
	tmp = (unsigned char *)src;
	if (!pt && !tmp)
		return (0);
	if (tmp < pt)
	{
		i++;
		while (i <= n)
		{
			pt[n - i] = tmp[n - i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			*(pt++) = *(tmp++);
	}
	return (dest);
}
