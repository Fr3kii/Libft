/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:55:25 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:38:31 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

long	ft_atoi(const char *nptr)
{
	long	i;
	int				sign;

	i = 0;
	sign = 1;
	while (*nptr != '\0' && (*nptr == 32 || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		i = i * 10 + (*nptr - '0');
		nptr++;
	}
	return (i * sign);
}
