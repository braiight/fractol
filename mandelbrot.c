/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:36:31 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 14:36:41 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_calc_mand(double ca, double cb)
{
	int		n;
	double	a;
	double	b;
	double	aa;
	double	bb;

	n = 0;
	a = ca;
	b = cb;
	while (n < MAX_ITER)
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

void	ft_draw_mand(t_fract *mand)
{
	double			x;
	double			y;
	int				n;
	static double	z_range = 10;

	z_range = 10 / mand->zoom;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mand->pix_r = mand->ca + ((x / WIDTH) * z_range - z_range / 2.0);
			mand->pix_i = mand->cb + ((y / HEIGHT) * z_range - z_range / 2.0);
			n = ft_calc_mand(mand->pix_r, mand->pix_i);
			if (n == MAX_ITER)
				mlx_put_pixel(mand->img, x, y, 0);
			else
				mlx_put_pixel(mand->img, x, y, mand->color * n);
			x++;
		}
		y++;
	}
}
