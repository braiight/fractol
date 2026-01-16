/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:45:47 by gumallet          #+#    #+#             */
/*   Updated: 2026/01/16 16:53:30 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Library includes */

# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

/* Rendering Macros */

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define MAX_ITER_JULIA 50
# define MAX_ITER_SHIP 50

/* String Macros for the guide */

# define WELCOME "Welcome to my fract_ol project!\n"
# define INSTR "Here are the available arguments to run the program:\n\n"
# define MANDEL "Mandelbrot: This argument lets you see the Mandelbrot set.\n"
# define M_INST "-Zoom in and out with mouse wheel.\n"
# define M_INSTR "-The zoom follows your cursor, "
# define M_INSTRU "and you can also move around with the WASD keys.\n\n"
# define JULI "Julia_Fixed a b: Replace a and b with the real and imaginary "
# define JULIA "components of a complex number to see its Julia set.\n"
# define JULIAA "-NOTE: Only use numbers strictly greater than"
# define JULIAAA " -2 and less than 2\n"
# define JULIAAAA "-Do not use leading zeroes on the whole number\n"
# define JULIAAAAA "-Move around as you would in the Mandelbrot set\n\n"
# define JULIAAAAAA "Julia_Dynamic: Your mouse movements control how "
# define JULIAAAAAAA "the Julia set evolves\n\n"
# define SHIP "Ship: This argument lets you see the Burning Ship fractal.\n"
# define SHIPP "-Again, same movements as the Mandelbrot set.\n\n"
# define COLOR "For all fractals, change the color palette by pressing C\n"

# define VALID_ARG "Please enter numbers strictly "
# define VALID_ARGS "greater than -2 and less than 2.\n"
# define VALID_ARGSS "-Do not use leading zeroes on the whole number\n"
# define VALID_ARGSSS "-Do not enter a number with more than 9 decimals\n"

/* Fractal struct */

typedef struct s_fract
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		ca;
	double		cb;
	double		pix_r;
	double		pix_i;
	double		zoom;
	double		center_step;
	double		jx;
	double		jy;
	uint32_t	color;
}	t_fract;

/* Struct for atod function */

typedef struct s_atod_values
{
	int		i;
	int		sign;
	double	res;
	double	whole;
	int		zeroes;
}	t_atod_values;

/* Functions to initialize the different structs */

int			ft_center_init(t_fract *fractal, char *stra, char *strb);
t_fract		*ft_julia_init(mlx_t *mlx, mlx_image_t *img);
t_fract		*ft_mand_init(mlx_t *mlx, mlx_image_t *img);

/* Mandelbrot functions */

void		ft_exec_mand(void);
void		ft_draw_mand(t_fract *mand);
void		ft_mouse_loop(double xdelta, double ydelta, void *frac);
void		ft_kb_loop(mlx_key_data_t keydata, void *frac);

/* Julia functions */

void		ft_update_julia(void *frac);
void		ft_kb_loop_julia_dynamic(mlx_key_data_t keydata, void *frac);
void		ft_mouse_loop_julia_fixed(double xdelta, double ydelta, void *frac);
void		ft_kb_loop_julia_fixed(mlx_key_data_t keydata, void *frac);
void		ft_update_pos_julia(t_fract *fractal);
void		ft_exec_julia_fixed(char *stra, char *strb);
void		ft_draw_julia(t_fract *julia);
void		ft_draw_julia_fixed(t_fract *julia);
void		ft_exec_julia_dynamic(void);
int			ft_calc_julia(double a, double b, double ca, double cb);

/* Burning Ship functions*/

void		ft_exec_ship(void);
void		ft_draw_ship(t_fract *mand);
void		ft_mouse_loop_ship(double xdelta, double ydelta, void *frac);
void		ft_kb_loop_ship(mlx_key_data_t keydata, void *frac);

/* Parsing & misc. utility functions */

void		ft_clean_close(void *frac);
int			ft_check_args(int argc, char **argv);
void		ft_guide(void);
int			ft_valid_julia(char *str);
double		ft_weak_atod(char *str, t_atod_values *val);
uint32_t	ft_change_color(uint32_t color);

#endif
