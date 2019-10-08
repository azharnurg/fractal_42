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
			ft_putendl("Gmme one file");
}

int				deal_key(int key, void *param)
{
	if (key == 53)
	{
		ft_putendl("IT is time to go Bye Bye");
		exit(0);
	}
	
	return (0);
}

void init_window_julia(t_fract *set)
{
	set->mlx_ptr = mlx_init();
	set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "FRACTOL");
	set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
	draw_julia(set->img_ptr);
	mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
	mlx_key_hook(set->win_ptr, deal_key, (void *)0);	
	mlx_loop(set->mlx_ptr);
}
void init_window_mandel(t_fract *set)
{
	set->mlx_ptr = mlx_init();
	set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "FRACTOL");
	set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
	draw_mandel(set->img_ptr);
	mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
	mlx_key_hook(set->win_ptr, deal_key, (void *)0);	
	mlx_loop(set->mlx_ptr);
}
void init_window_ship(t_fract *set)
{
	set->mlx_ptr = mlx_init();
	set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "FRACTOL");
	set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
	draw_ship(set->img_ptr);
	mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
	mlx_key_hook(set->win_ptr, deal_key, (void *)0);	
	mlx_loop(set->mlx_ptr);
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
			init_window_mandel(var->img_ptr);
		}
		else if (ft_strcmp(av[1], "J") == 0)
		{
			draw_julia(var->img_ptr);
		}
		else if (ft_strcmp(av[1], "S") == 0)
		{
			draw_mandel(var->img_ptr);
		}
	}
	else
		ft_putendl("Error: Gimme one fractal");
	return (0);
}