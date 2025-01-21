/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:38:25 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 14:27:12 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	ft_abs(double num)
{
	if (num < 0)
		num = -num;
	return (num);
}

static int	ft_calc_ship(double ca, double cb)
{
	int		n;
	double	a;
	double	b;
	double	aa;
	double	bb;

	n = 0;
	a = ca;
	b = cb;
	while (n < MAX_ITER_SHIP)
	{
		aa = ft_abs(a) * ft_abs(a) - ft_abs(b) * ft_abs(b);
		bb = 2 * ft_abs(a) * ft_abs(b);
		a = aa + ca;
		b = bb + cb;
		if (a * a + b * b > 4)
			return (n);
		n++;
	}
	return (n);
}

void	ft_draw_ship(t_fract *ship)
{
	double			x;
	double			y;
	int				n;
	static double	z_range = 10;

	z_range = 10 / ship->zoom;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ship->pix_r = ship->ca + ((x / WIDTH) * z_range - z_range / 2.0);
			ship->pix_i = ship->cb + ((y / HEIGHT) * z_range - z_range / 2.0);
			n = ft_calc_ship(ship->pix_r, ship->pix_i);
			if (n == MAX_ITER_SHIP)
				mlx_put_pixel(ship->img, x, y, 0);
			else
				mlx_put_pixel(ship->img, x, y, ship->color * n);
			x++;
		}
		y++;
	}
}
