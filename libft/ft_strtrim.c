/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:35:52 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:41:35 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	start;
	size_t	end;

	dest = 0;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1);
		while (ft_strchr(set, s1[start]) && s1[start])
			start++;
		while (ft_strchr(set, s1[end - 1]) && end > start && s1[end - 1])
			end--;
		dest = (char *)malloc((end - start + 1) * sizeof(char));
		if (!dest)
			return (0);
		ft_strlcpy(dest, &s1[start], end - start + 1);
	}
	return (dest);
}
