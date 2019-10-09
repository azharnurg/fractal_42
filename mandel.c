/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:28:37 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/04 14:28:44 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
static int calc_iters_man(t_fract *var, int row, int col, double new_re)
{
  double pr; 
  double pi;    
  double old_re;
  double new_im;
  double old_im;
 var->zoom = 1; 
  var->move_x = -0.5; 
  var->move_y = 0; 
  var->max = 300;
    pr = 1.5 * (row - WIN_X / 2) / (0.5 * var->zoom * WIN_X) + var->move_x;
    pi = (col - WIN_Y / 2) / (0.5 * var->zoom * WIN_Y) + var->move_y;
    old_re = new_re = old_im = new_im = 0;
    int i = -1;
    while (++i < var->max && (SQR(new_re) + SQR(new_im)) <= 4.0)
    {
      old_re = new_re;
      old_im = new_im;
      new_re = SQR(old_re) - SQR(old_im) + pr;
      new_im = 2 * old_re * old_im + pi;
    
    }
    return (i);
}

void draw_mandel(void *img_ptr)
 {
	int col;
	int row;
 	int i;
 	char *data;
	int *color_arr;
  t_mlx mlx;
  t_fract var;

	color_arr = make_col_arr();
	data = mlx_get_data_addr(img_ptr, &mlx.bpp, &mlx.size_line, &mlx.endian);
	row = 0;
  while (row < WIN_X)
  {
    col = -1;
    while (++col < WIN_Y)
    {
    	i = calc_iters_man(&var, row, col, 64);
      if (i == 300)
				data[col * 4 + row * WIN_Y * 4] = BLACK;
			else
				data[col * 4 + row * WIN_Y * 4] = color_arr[i % 64];
	}
		row++;
  
  }
}

void init_window_mandel(t_fract *set)
{
  set->mlx_ptr = mlx_init();
  set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "MANDELBROT");
  set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
  draw_mandel(set->img_ptr);
  mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
  mlx_key_hook(set->win_ptr, deal_key, (void *)0);  
  mlx_loop(set->mlx_ptr);
}