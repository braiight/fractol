/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumallet <gumallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:01:15 by gumallet          #+#    #+#             */
/*   Updated: 2025/01/17 16:42:50 by gumallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"

int	main(int argc, char **argv)
{
	if (!ft_check_args(argc, argv))
	{
		ft_guide();
		return (1);
	}
	else if (ft_check_args(argc, argv) == 1)
		ft_exec_mand();
	else if (ft_check_args(argc, argv) == 2)
		ft_exec_julia_dynamic();
	else if (ft_check_args(argc, argv) == 3)
		ft_exec_julia_fixed(argv[2], argv[3]);
	else if (ft_check_args(argc, argv) == 4)
		ft_exec_ship();
	return (0);
}
