/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:40:28 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 14:10:53 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	mark;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			mark = i;
			while (big[i] == little[j] && i < len && little[j] && big[i])
			{
				i++;
				j++;
				if (little[j] == '\0')
					return ((char *)&big[mark]);
			}
			i = mark;
		}
		i++;
	}
	return (NULL);
}
