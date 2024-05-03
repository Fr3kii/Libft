/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:14:50 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:41:07 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*start;

	if (!s1 || !s2)
		return (0);
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (0);
	start = dest;
	while (*s1 != '\0')
	{
		*dest = *s1;
		dest++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*dest = *s2;
		dest++;
		s2++;
	}
	*dest = '\0';
	return (start);
}
