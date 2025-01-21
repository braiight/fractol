/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_dynamic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:05:50 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 12:22:36 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_calc_julia(double a, double b, double ca, double cb)
{
	int		n;
	double	aa;
	double	bb;

	n = 0;
	while (n < MAX_ITER_JULIA)
	{
		aa = a * a - b * b;
		bb = 2 * a * b;
		a = aa + ca;
		b = bb + cb;
		if (a * a + b * b > 4)
			return (n);
		n++;
	}
	return (n);
}

void	ft_draw_julia(t_fract *julia)
{
	double	x;
	double	y;
	int		n;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			julia->pix_r = ((x / WIDTH) * julia->zoom - julia->zoom / 2.0);
			julia->pix_i = ((y / HEIGHT) * julia->zoom - julia->zoom / 2.0);
			n = ft_calc_julia(julia->pix_r, julia->pix_i, julia->ca, julia->cb);
			if (n == MAX_ITER_JULIA)
				mlx_put_pixel(julia->img, x, y, 0);
			else
				mlx_put_pixel(julia->img, x, y, julia->color * n);
			x++;
		}
		y++;
	}
}
