/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:06:06 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:35:41 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_getformat(va_list args, const char form)
{
	int	num_char;

	num_char = 0;
	if (form == 'c')
		num_char += ft_putchar(va_arg(args, int));
	else if (form == 's')
		num_char += ft_putstr(va_arg(args, char *));
	else if (form == 'p')
		num_char += ft_putptr(va_arg(args, unsigned long long));
	else if (form == 'd' || form == 'i')
		num_char += ft_putnbr(va_arg(args, int));
	else if (form == 'u')
		num_char += ft_put_unsigned(va_arg(args, unsigned int));
	else if (form == 'x' || form == 'X')
		num_char += ft_put_hex(va_arg(args, unsigned int), form);
	else if (form == '%')
		num_char += ft_put_pourcent();
	return (num_char);
}

int	ft_printf(const char *c, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, c);
	while (c[i] != '\0')
	{
		if (c[i] == '%')
		{
			length += ft_getformat(args, c[i + 1]);
			i++;
		}
		else
			length += ft_putchar(c[i]);
		i++;
	}
	va_end(args);
	return (length);
}
