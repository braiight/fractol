/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   housekeeping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:56:38 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/20 15:15:29 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_clean_close(void *frac)
{
	t_fract	*fractal;

	if (!frac)
		return ;
	fractal = frac;
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_close_window(fractal->mlx);
	free(fractal);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (!ft_strncmp(argv[1], "Mandelbrot", 11))
		return (1);
	else if (!ft_strncmp(argv[1], "Julia_Dynamic", 14))
		return (2);
	else if (!ft_strncmp(argv[1], "Julia_Fixed", 12))
	{
		if (argv[2] && argv[3])
			return (3);
	}
	else if (!ft_strncmp(argv[1], "Ship", 5))
		return (4);
	return (0);
}

void	ft_guide(void)
{
	ft_putstr_fd(WELCOME, 2);
	ft_putstr_fd(INSTR, 2);
	ft_putstr_fd(MANDEL, 2);
	ft_putstr_fd(M_INST, 2);
	ft_putstr_fd(M_INSTR, 2);
	ft_putstr_fd(M_INSTRU, 2);
	ft_putstr_fd(JULI, 2);
	ft_putstr_fd(JULIA, 2);
	ft_putstr_fd(JULIAA, 2);
	ft_putstr_fd(JULIAAA, 2);
	ft_putstr_fd(JULIAAAA, 2);
	ft_putstr_fd(JULIAAAAA, 2);
	ft_putstr_fd(JULIAAAAAA, 2);
	ft_putstr_fd(JULIAAAAAAA, 2);
	ft_putstr_fd(SHIP, 2);
	ft_putstr_fd(SHIPP, 2);
	ft_putstr_fd(COLOR, 2);
}

int	ft_valid_julia(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] != '0' && str[i] != '1')
		return (0);
	i++;
	if (str[i] != '\0' && str[i] != '.')
		return (0);
	if (!str[i])
		return (1);
	i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || j > 8)
			return (0);
		i++;
		j++;
	}
	return (1);
}

double	ft_weak_atod(char *str, t_atod_values *val)
{
	val->whole = (double)ft_atoi(str);
	if (str[val->i++] == '-')
		val->sign *= -1;
	while (str[val->i] && str[val->i] != '.' && ft_isdigit(str[val->i]))
		val->i++;
	if (str[val->i] == '.')
		val->i++;
	while (str[val->i] && str[val->i] == '0')
	{
		val->i++;
		val->zeroes++;
	}
	str = str + val->i;
	val->res = (double)ft_atoi(str);
	while (val->res > 1)
		val->res /= 10;
	while (val->zeroes)
	{
		val->zeroes--;
		val->res /= 10;
	}
	val->res += (double)val->whole;
	return (val->res * (double)val->sign);
}
