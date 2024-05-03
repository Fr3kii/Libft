/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:04:03 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:41:38 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;
	size_t			j;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	i = ft_strlen(s + start);
	if (i < len)
		len = i;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	j = 0;
	while (j < len)
	{
		dest[j] = s[start + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
