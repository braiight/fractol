/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:41:21 by gumallet          #+#    #+#             */
/*   Updated: 2024/10/30 17:02:17 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long n)
{
	int	i;

	i = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	my_int;

	my_int = (long)n;
	len = ft_num_len(my_int);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (my_int == 0)
		res[0] = '0';
	if (my_int < 0)
	{
		res[0] = '-';
		my_int = -my_int;
	}
	res[len] = '\0';
	while (my_int > 0)
	{
		len--;
		res[len] = (my_int % 10) + 48;
		my_int = my_int / 10;
	}
	return (res);
}
