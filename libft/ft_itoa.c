/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:01:16 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:39:21 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	len_int(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*dest;
	int				size;
	long int		num;

	num = n;
	size = len_int(num);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	dest[size] = '\0';
	if (num < 0)
	{
		dest[0] = '-';
		num *= -1;
	}
	else if (num == 0)
		dest[0] = '0';
	while (num != 0)
	{
		dest[--size] = (num % 10) + '0';
		num /= 10;
	}
	return (dest);
}
