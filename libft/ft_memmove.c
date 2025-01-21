/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:34:06 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 13:49:46 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_d;
	char		*temp_s;
	size_t		i;

	i = 0;
	temp_d = (char *)dest;
	temp_s = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
	{
		while (i < n)
		{
			temp_d[i] = temp_s[i];
			i++;
		}
	}
	else
	{
		temp_d = temp_d + (n - 1);
		temp_s = temp_s + (n - 1);
		while (i++ < n)
			*temp_d-- = *temp_s--;
	}
	return (dest);
}
