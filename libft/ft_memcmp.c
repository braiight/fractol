/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:05:46 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 13:49:05 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*comp1;
	unsigned char	*comp2;

	i = 0;
	comp1 = (unsigned char *)s1;
	comp2 = (unsigned char *)s2;
	while (i < n)
	{
		if (comp1[i] != comp2[i])
			return (comp1[i] - comp2[i]);
		i++;
	}
	return (0);
}
