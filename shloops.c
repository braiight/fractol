/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shloops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:49:36 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 14:37:49 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_kb_loop_ship(mlx_key_data_t keydata, void *frac)
{
	t_fract	*fractal;

	fractal = frac;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		fractal->cb = fractal->cb - fractal->center_step;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		fractal->ca = fractal->ca - fractal->center_step;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		fractal->cb = fractal->cb + fractal->center_step;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		fractal->ca = fractal->ca + fractal->center_step;
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		fractal->color = ft_change_color(fractal->color);
	if (keydata.action == MLX_PRESS)
		ft_draw_ship(fractal);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_clean_close(fractal);
	fractal->center_step = (1 / fractal->zoom) * 2;
}

static void	ft_update_pos_ship(t_fract *fractal)
{
	int	xmouse;
	int	ymouse;

	xmouse = 0;
	ymouse = 0;
	mlx_get_mouse_pos(fractal->mlx, &xmouse, &ymouse);
	if (xmouse < 0 || ymouse < 0 || xmouse > WIDTH || ymouse > HEIGHT)
		return ;
	if (xmouse < WIDTH / 3)
		fractal->ca -= fractal->center_step;
	else if (xmouse > (WIDTH / 3) * 2)
		fractal->ca += fractal->center_step;
	if (ymouse < HEIGHT / 3)
		fractal->cb -= fractal->center_step;
	else if (ymouse > (HEIGHT / 3) * 2)
		fractal->cb += fractal->center_step;
	fractal->zoom *= 1.5;
	fractal->center_step = (1 / fractal->zoom) * 2;
	ft_draw_ship(fractal);
}

void	ft_mouse_loop_ship(double xdelta, double ydelta, void *frac)
{
	static t_fract	*fractal;
	static double	step = 2.0;

	fractal = frac;
	(void)xdelta;
	if (ydelta > 0)
		ft_update_pos_ship(fractal);
	else if (ydelta < 0)
	{
		fractal->zoom /= 1.5;
		if (fractal->zoom < 1)
		{
			fractal->zoom = 1;
			step = 2;
		}
		ft_draw_ship(fractal);
	}
	if (fractal->zoom / step > 10)
		step *= 2;
}
