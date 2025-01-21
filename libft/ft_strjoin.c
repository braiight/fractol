/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:59:58 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 17:05:20 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*mash;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	mash = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!mash)
		return (NULL);
	while (s1[i] != '\0')
	{
		mash[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		mash[i + j] = s2[j];
		j++;
	}
	mash[i + j] = '\0';
	return (mash);
}
