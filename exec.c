/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:38:15 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 15:48:48 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_exec_mand(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fract		*fractal;

	mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", 1);
	if (!mlx)
		return ;
	mlx_set_setting(0, true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (mlx_close_window(mlx));
	fractal = ft_mand_init(mlx, img);
	if (!fractal)
		return (mlx_delete_image(mlx, img), mlx_close_window(mlx));
	ft_draw_mand(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_key_hook(fractal->mlx, ft_kb_loop, fractal);
	mlx_scroll_hook(fractal->mlx, ft_mouse_loop, fractal);
	mlx_close_hook(fractal->mlx, ft_clean_close, fractal);
	mlx_loop(fractal->mlx);
}

void	ft_exec_julia_dynamic(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fract		*fractal;

	mlx = mlx_init(WIDTH, HEIGHT, "Dynamic Julia Sets", 1);
	if (!mlx)
		return ;
	mlx_set_setting(0, true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (mlx_close_window(mlx));
	fractal = ft_julia_init(mlx, img);
	if (!fractal)
		return (mlx_delete_image(mlx, img), mlx_close_window(mlx));
	ft_draw_julia(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_loop_hook(fractal->mlx, ft_update_julia, fractal);
	mlx_key_hook(fractal->mlx, ft_kb_loop_julia_dynamic, fractal);
	mlx_close_hook(fractal->mlx, ft_clean_close, fractal);
	mlx_loop(fractal->mlx);
}

static void	ft_guide_args(void)
{
	ft_putstr_fd(VALID_ARG, 2);
	ft_putstr_fd(VALID_ARGS, 2);
	ft_putstr_fd(VALID_ARGSS, 2);
	ft_putstr_fd(VALID_ARGSSS, 2);
	return ;
}

void	ft_exec_julia_fixed(char *stra, char *strb)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fract			*fractal;

	if (!ft_valid_julia(stra) || !ft_valid_julia(strb))
		return (ft_guide_args());
	mlx = mlx_init(WIDTH, HEIGHT, "Fixed Julia Set", 1);
	if (!mlx)
		return ;
	mlx_set_setting(0, true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img)
		return (mlx_close_window(mlx));
	fractal = ft_julia_init(mlx, img);
	if (!fractal)
		return (mlx_delete_image(mlx, img), mlx_close_window(mlx));
	if (ft_center_init(fractal, stra, strb) == -1)
		return (ft_clean_close(fractal));
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	ft_draw_julia_fixed(fractal);
	mlx_key_hook(fractal->mlx, ft_kb_loop_julia_fixed, fractal);
	mlx_scroll_hook(fractal->mlx, ft_mouse_loop_julia_fixed, fractal);
	mlx_close_hook(fractal->mlx, ft_clean_close, fractal);
	mlx_loop(fractal->mlx);
}

void	ft_exec_ship(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_fract		*fractal;

	mlx = mlx_init(WIDTH, HEIGHT, "Burning Ship", 1);
	mlx_set_setting(0, true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	fractal = ft_mand_init(mlx, img);
	if (!fractal)
		return ;
	ft_draw_ship(fractal);
	mlx_image_to_window(fractal->mlx, fractal->img, 0, 0);
	mlx_key_hook(fractal->mlx, ft_kb_loop_ship, fractal);
	mlx_scroll_hook(fractal->mlx, ft_mouse_loop_ship, fractal);
	mlx_close_hook(fractal->mlx, ft_clean_close, fractal);
	mlx_loop(fractal->mlx);
}
