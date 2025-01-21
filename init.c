/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:22:03 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 15:23:54 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_atod_values	*ft_valatod_init(void)
{
	t_atod_values	*norme;

	norme = malloc(sizeof(t_atod_values));
	norme->i = 0;
	norme->res = 0;
	norme->sign = 1;
	norme->whole = 0;
	norme->zeroes = 0;
	return (norme);
}

int	ft_center_init(t_fract *fractal, char *stra, char *strb)
{
	t_atod_values	*val;

	val = ft_valatod_init();
	if (!val)
		return (-1);
	fractal->ca = ft_weak_atod(stra, val);
	free(val);
	val = ft_valatod_init();
	if (!val)
		return (-1);
	fractal->cb = ft_weak_atod(strb, val);
	free(val);
	return (0);
}

t_fract	*ft_julia_init(mlx_t *mlx, mlx_image_t *img)
{
	t_fract	*fractal;

	fractal = (t_fract *)malloc(sizeof(t_fract));
	if (!fractal)
		return (NULL);
	fractal->mlx = mlx;
	fractal->img = img;
	fractal->ca = 0;
	fractal->cb = 0;
	fractal->pix_r = 0;
	fractal->pix_i = 0;
	fractal->zoom = 5;
	fractal->center_step = 0.01;
	fractal->jx = 0;
	fractal->jy = 0;
	fractal->color = 0xFCBE11;
	return (fractal);
}

t_fract	*ft_mand_init(mlx_t *mlx, mlx_image_t *img)
{
	t_fract	*fractal;

	fractal = (t_fract *)malloc(sizeof(t_fract));
	if (!fractal)
		return (NULL);
	fractal->mlx = mlx;
	fractal->img = img;
	fractal->ca = 0;
	fractal->cb = 0;
	fractal->pix_r = 0;
	fractal->pix_i = 0;
	fractal->zoom = 1;
	fractal->center_step = 0.1;
	fractal->jx = 0;
	fractal->jy = 0;
	fractal->color = 0xFCBE11;
	return (fractal);
}
