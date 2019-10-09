/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:52:15 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/07 15:52:19 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void choose_fract(char **av)
{
	t_fract *var;
	if (ft_strcmp(av[1], "M") == 0)
		{
			draw_mandel(var->img_ptr);
		}
		else if (ft_strcmp(av[1], "J") == 0)
		{
			draw_julia(var->img_ptr);
		}
		else if (ft_strcmp(av[1], "S") == 0)
		{
			draw_ship(var->img_ptr);
		}
		else 
			ft_putendl("Gimme one fractal: M - Mandelbrot; J - Julia; S - BurningShip.");
}

int main (int ac, char **av)
{
	t_fract *var;

	if (!(var = ft_memalloc(sizeof(t_fract))))
		ft_putendl("error: memalloc");
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "M") == 0)
		{
			init_window_mandel(var);
		}
		else if (ft_strcmp(av[1], "J") == 0)
		{
			init_window_julia(var);
		}
		else if (ft_strcmp(av[1], "S") == 0)
		{
			init_window_ship(var);
		}
		else 
			ft_putendl("error: wrong fractal");
	}
	else
		ft_putendl("Gimme one fractal: M - Mandelbrot; J - Julia; S - BurningShip.");
	return (0);
}