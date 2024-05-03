/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:25:50 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:38:38 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*set;
	size_t	limit;

	limit = nmemb * size;
	if (nmemb != 0 && size != 0)
	{
		if (limit / size != nmemb)
			return (0);
	}
	set = malloc(limit);
	if (!set)
		return (0);
	ft_bzero(set, limit);
	return (set);
}
