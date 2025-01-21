/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:43:24 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:37:42 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*adr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		adr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = adr;
	}
}
