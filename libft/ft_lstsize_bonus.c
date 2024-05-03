/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:25:42 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:40:03 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cmp;

	if (!lst)
		return (0);
	cmp = 0;
	while (lst->next != 0)
	{
		lst = lst->next;
		cmp++;
	}
	cmp++;
	return (cmp);
}
