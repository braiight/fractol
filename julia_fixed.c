/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fixed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:47:53 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 12:22:25 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_draw_julia_fixed(t_fract *julia)
{
	double	x;
	double	y;
	int		n;
	double	z_range;

	z_range = 20 / julia->zoom;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			julia->pix_r = julia->jx + ((x / WIDTH) * z_range - z_range / 2.0);
			julia->pix_i = julia->jy + ((y / HEIGHT) * z_range - z_range / 2.0);
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

void	ft_update_pos_julia(t_fract *fractal)
{
	int	xmouse;
	int	ymouse;

	xmouse = 0;
	ymouse = 0;
	mlx_get_mouse_pos(fractal->mlx, &xmouse, &ymouse);
	if (xmouse < 0 || ymouse < 0 || xmouse > WIDTH || ymouse > HEIGHT)
		return ;
	if (xmouse < WIDTH / 3)
		fractal->jx -= fractal->center_step * 2;
	else if (xmouse > (WIDTH / 3) * 2)
		fractal->jx += fractal->center_step * 2;
	if (ymouse < HEIGHT / 3)
		fractal->jy -= fractal->center_step * 2;
	else if (ymouse > (HEIGHT / 3) * 2)
		fractal->jy += fractal->center_step * 2;
	fractal->zoom *= 1.2;
	fractal->center_step = (1 / fractal->zoom) / 2;
	ft_draw_julia_fixed(fractal);
}
