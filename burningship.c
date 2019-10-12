/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:31:35 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/04 17:31:54 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	calc_iters_b(t_fract *var, int row, int col)
{
	double	new_im;
	double	new_re;
	double	pr;
	double	pi;
	int		i;
	int old_im;
	double old_re;

	new_re = 0;
	new_im = 0;
	pr = 2.0 * (col - WIN_X / 2) / (0.5 * var->zoom * WIN_X) + var->move_x;
	pi = 2.0 * (row - WIN_Y / 2) / (0.5 * var->zoom * WIN_Y) + var->move_y;
	i = -1;
	while (SQR(new_re) + SQR(new_im) <= 4.0 && ++i < var->max)
	{
		old_re = SQR(new_re) - SQR(new_im) + pr;
		new_im = 2 * fabs(new_re * new_im) + pi;
		new_re = old_re;
	}
	return (i);
}

void		draw_ship(t_fract *set)
{
	int col;
	int row;
 	int i;

	row = 0;
  while (row < WIN_X)
  {
    col = -1;
    while (++col < WIN_Y)
    {
    	i = calc_iters_b(set, row, col);
      if (i == 300)
				set->data[col * 4 + row * WIN_Y * 4] = BLACK;
			else
				set->data[col * 4 + row * WIN_Y * 4] = set->color_arr[i % 100];
	}
		row++;
  
  }
}

static void setup_env(t_fract *var)
{
 var->zoom = 1;   
  var->move_x = -0.5; 
  var->move_y = 0; 
  var->max = 1024;

}

void init_window_ship(t_fract *set)
{
	set->mlx_ptr = mlx_init();
	set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "BURNING SHIP");
	set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
	set->data =mlx_get_data_addr(set->img_ptr, &(set->mlx_data.bpp), &(set->mlx_data.size_line), &(set->mlx_data.endian));
  	set->color_arr = make_col_arr();
  	setup_env(set);
 	draw_ship(set);
  	mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
  	mlx_key_hook(set->win_ptr, deal_key, (void *)0);  
 	mlx_mouse_hook(set->win_ptr, mouse_hooks, set);
	mlx_loop(set->mlx_ptr);
}