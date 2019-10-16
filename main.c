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

void		make_col_arr(t_fract *set)
{
	int				c;
	float			r;

	set->color_arr = (int *)malloc(sizeof(int) * set->max);
	c = 0;
	r = 0;
	while (c++ <  set->max)
	{
		set->rgb.r = (cos(r) + 1) * 127;
		set->rgb.g = (sin(r) + 1) * 127;
		set->rgb.b = (-cos(r) + 1) * 127;
		set->color_arr[c] = set->rgb.b | set->rgb.g << 4 | set->rgb.r << 16;
		r += M_PI / set->max;
	}
} 

int 		*make_col_arr2(void)
{
	int *colARR = (int *)malloc(sizeof(int) * 16);

	colARR[0] = 0x421E0F;
	colARR[1] = 0x19071A;
	colARR[2] = 0x09012F;
	colARR[3] = 0x040449;
	colARR[4] = 0x000764;
	colARR[5] = 0x0C2C8A;
	colARR[6] = 0x182C8A;
	colARR[7] = 0x397DD1;
	colARR[8] = 0x86B5E5;
	colARR[9] = 0xD3ECF8;
	colARR[10] = 0xF1E9BF;
	colARR[11] = 0xF8C95F;
	colARR[12] = 0xFFAA00;
	colARR[13] = 0xCC8000;
	colARR[14] = 0x995700;
	colARR[15] = 0x6A3403;

	return (colARR);	
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

void setup_env(t_fract *set)
{
	set->zoom = .90; 
	set->move_x = 0;
	set->move_y = 0;
	set->max = 64;
	set->flag = 0;
	set->color_arr = make_col_arr2();
	
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
  		set->data = mlx_get_data_addr(set->img_ptr, &set->bpp, &set->size_line, &set->endian);
  		int i = 0;
  		while(set->data[i])
  		{
  			printf("i = %d\n", i);
  			i++;
  		}
  		setup_env(set);
 		choose_fract(set);
		mlx_key_hook(set->win_ptr, deal_key, set);
		mlx_mouse_hook(set->win_ptr, mouse_hooks, set);
 		mlx_hook(set->win_ptr, 6, 0, julia_mouse_hook, set);
 		mlx_loop(set->mlx_ptr);
	}
	else
		ft_putendl("Gimme one fractal: M - Mandelbrot; J - Julia; S - BurningShip; JX = Julia Explorer.");
	return (0);
}