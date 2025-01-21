/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julioops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:31:46 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 14:36:09 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_kb_loop_julia_dynamic(mlx_key_data_t keydata, void *frac)
{
	t_fract	*fractal;

	fractal = frac;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		fractal->color = ft_change_color(fractal->color);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_clean_close(fractal);
}

void	ft_kb_loop_julia_fixed(mlx_key_data_t keydata, void *frac)
{
	t_fract	*fractal;

	fractal = frac;
	fractal->center_step = 1 / fractal->zoom;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		fractal->jy -= fractal->center_step;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		fractal->jx -= fractal->center_step;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		fractal->jy += fractal->center_step;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		fractal->jx += fractal->center_step;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		fractal->color = ft_change_color(fractal->color);
	if (keydata.action == MLX_PRESS)
		ft_draw_julia_fixed(fractal);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_clean_close(fractal);
}

void	ft_mouse_loop_julia_fixed(double xdelta, double ydelta, void *frac)
{
	static t_fract	*fractal;
	static double	step = 1.0;

	fractal = frac;
	(void)xdelta;
	if (ydelta > 0)
		ft_update_pos_julia(fractal);
	else if (ydelta < 0)
	{
		fractal->zoom /= 1.2;
		if (fractal->zoom < 2)
		{
			fractal->zoom = 2;
			step = 1;
		}
		ft_draw_julia_fixed(fractal);
	}
	if (fractal->zoom / step > 10)
		step *= 1.2;
}

static double	ft_convert_mouse_pos(int mouse, int dimension)
{
	double	res;

	dimension -= (dimension / 2);
	res = ((double)mouse - (double)dimension) / (double)dimension;
	return (res);
}

void	ft_update_julia(void *frac)
{
	t_fract	*fractal;
	int		i;
	int		xmouse;
	int		ymouse;

	i = 0;
	fractal = frac;
	if (i % 1000 == 0)
	{
		mlx_get_mouse_pos(fractal->mlx, &xmouse, &ymouse);
		if (xmouse < 0 || ymouse < 0 || xmouse > WIDTH || ymouse > HEIGHT)
			return ;
		fractal->ca = ft_convert_mouse_pos(xmouse, WIDTH);
		fractal->cb = ft_convert_mouse_pos(ymouse, HEIGHT);
		ft_draw_julia(fractal);
	}
	i++;
	if (i > 10000001)
		i = 0;
}
