/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:58:46 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:44:24 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_unsigned_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int u)
{
	int		length;
	char	*num;

	length = ft_unsigned_len(u);
	num = (char *)malloc(sizeof(char) * (length + 1));
	if (!num)
		return (0);
	num[length] = '\0';
	while (u != 0)
	{
		num[length - 1] = u % 10 + '0';
		u = u / 10;
		length--;
	}
	return (num);
}

int	ft_put_unsigned(unsigned int u)
{
	int		length;
	char	*num;

	length = 0;
	if (u == 0)
		length = write(1, "0", 1);
	else
	{
		num = ft_uitoa(u);
		length = ft_putstr(num);
		free(num);
	}
	return (length);
}
