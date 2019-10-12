/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 16:43:04 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/03 16:43:08 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static	int	calc_iters(t_fract *var, int row, int col)
{
	double	old_re;
	double	old_im;
	double	new_re;
	double	new_im;
	int		i;

	new_re = 1.5 * (row - WIN_X / 2) / (0.5 * var->zoom * WIN_X) + var->move_x;
	new_im = 1.5 * (col - WIN_Y / 2) / (0.5 * var->zoom * WIN_Y) + var->move_y;
	i = -1;
	while (++i < var->max && SQR(new_re) + SQR(new_im) <= 4.0)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = SQR(old_re) - SQR(new_im) + (var->move_x * 4.0 / WIN_X - 2.0);
		new_im = 2 * (old_im * old_re) + (var->move_y * 4.0 / WIN_Y - 2.0);
	}
	return (i);
}

void	draw_julia(t_fract *set)
{
	t_mlx mlx;
	int	i;
	int	col;
	int row;

	row = 0;
	while (row < WIN_X)
	{
		col = 0;
		while (++col < WIN_Y)
		{
			i = calc_iters(set, row, col);
			if (i == 64)
				set->data[col * 4 + row * (WIN_Y * 4)] = BLACK;
			
				set->data[col * 4 + row * (WIN_Y * 4)] = set->color_arr[i % 64];
		}
		row++;
	}
}

static void setup_env(t_fract *var)
{
 var->zoom = 1;   
  var->move_x = 0; 
  var->move_y = 0; 
  var->max = 300;
}
void init_window_julia(t_fract *set)
{
  set->mlx_ptr = mlx_init();
  set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "JULIA");
  set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
  set->data = mlx_get_data_addr(set->img_ptr, &(set->mlx_data.bpp), &(set->mlx_data.size_line), &(set->mlx_data.endian));
  set->color_arr = make_col_arr();
  setup_env(set);
  draw_julia(set);
  mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
  mlx_key_hook(set->win_ptr, deal_key, (void *)0);  
 mlx_mouse_hook(set->win_ptr, mouse_hooks, set);
 mlx_hook(set->win_ptr, 6, 0, julia_mouse_hook, set);
  mlx_loop(set->mlx_ptr);
}