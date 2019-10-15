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

void choose_fract(t_fract *set)
{
	if (set->fract_num == 0)
		exit(0);
	else
		thread(set);
	mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
}

void inputchoise(char av, t_fract *set)
{
	if (av == 'M')
		{
			set->fract_num = 1;
		}
		else if (av == 'J')
		{
			set->fract_num = 2;
		}
		else if (av == 'S')
		{
			set->fract_num = 3;
		}
		//else if (av == 'X')
		//	init_window_jx(set);
		else
			set->fract_num = 0;
}
static void setup_env(t_fract *set)
{
	set->zoom = 1; 
	set->move_x = 0;
	set->move_y = 0;
	set->max = 64;
	set->flag = 0;
	make_col_arr(set);

}

int main (int ac, char **av)
{
	t_fract *set;

	if (ac == 2)
	{	
		if (!(set = ft_memalloc(sizeof(t_fract))))
			return (0);
		inputchoise(av[1][0], set);
		if (!(set->fract_num))
			ft_putendl("fractal not found");
		set->mlx_ptr = mlx_init();
  		set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "JULIA");
		set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_X, WIN_Y);
  		set->data = mlx_get_data_addr(set->img_ptr, &(set->mlx_data.bpp), &(set->mlx_data.size_line), &(set->mlx_data.endian));
  		setup_env(set);
 		choose_fract(set);
		mlx_key_hook(set->win_ptr, deal_key, set);
		//mlx_mouse_hook(set->win_ptr, mouse_hooks, set);
 		//mlx_hook(set->win_ptr, 6, 0, julia_mouse_hook, set);
 		mlx_loop(set->mlx_ptr);
	}
	else
		ft_putendl("Gimme one fractal: M - Mandelbrot; J - Julia; S - BurningShip; JX = Julia Explorer.");
	return (0);
}