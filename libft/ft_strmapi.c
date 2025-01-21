/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:41:10 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 17:10:36 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*modif;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	modif = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!modif)
		return (NULL);
	while (s[i])
	{
		modif[i] = f(i, s[i]);
		i++;
	}
	modif[i] = '\0';
	return (modif);
}
