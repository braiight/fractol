/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:25:52 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 17:23:29 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char const *set, char comp)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == comp)
			return (0);
		else
			i++;
	}
	return (1);
}

static size_t	ft_trim_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (ft_is_charset(set, s1[i - 1]) == 0)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*res;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (ft_is_charset(set, s1[i]) == 0)
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	end = ft_trim_end(s1, set);
	start = i;
	res = (char *)malloc(sizeof(char) * ((end - i) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	return (res[i] = '\0', res);
}
