/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:39:19 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:44:19 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, sizeof(char));
	return (1);
}

void	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], sizeof(char));
		i++;
	}
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], sizeof(char));
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*num;
	int		length;

	length = 0;
	num = ft_itoa(n);
	length += ft_putstr(num);
	free(num);
	return (length);
}

int	ft_put_pourcent(void)
{
	return (ft_putchar('%'));
}
