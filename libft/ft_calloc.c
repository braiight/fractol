/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:09:53 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/31 11:35:48 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*tot_block;

	i = 0;
	if (size != 0)
		if (nmemb >= (SIZE_MAX / size))
			return (NULL);
	tot_block = malloc(nmemb * size);
	if (tot_block == 0)
		return (tot_block);
	ft_bzero(tot_block, nmemb * size);
	return (tot_block);
}
