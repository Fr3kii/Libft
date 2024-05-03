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

int	ft_atoi(const char *nptr)
{
	unsigned long	i;
	int				sign;

	i = 0;
	sign = 1;
	while (*nptr != '\0' && (*nptr == 32 || (*nptr >= 9 && *nptr <= 13)))
		nptr++;
	if (*nptr == 45)
	{
		sign *= -1;
		nptr++;
	}
	else if (*nptr == 43)
		nptr++;
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		i = i * 10 + (*nptr - '0');
		if ((i > LONG_MAX) && sign == 1)
			return (-1);
		else if ((i > LONG_MAX) && sign == -1)
			return (0);
		nptr++;
	}
	return (i * sign);
}
