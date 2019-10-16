/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:18:39 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/08 20:18:56 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*int			calc_iters_heart(t_fract *set, int row, int col)
{
	double	new_im;
	double	new_re;
	int		i;
	double old_im;
	double old_re;
	set->zoom = 1; 
  set->move_x = 0; 
  set->move_y = 0; 
  set->max = 128;

	new_re = 1.5 * (row - WIN_X / 2) / (0.5 * set->zoom * WIN_X) + set->move_x;
	new_im = 1.5 * (col - WIN_Y / 2) / (0.5 * set->zoom * WIN_Y) + set->move_y;
	new_re = (set->mouse_x - WIN_X) / ((double)WIN_X * 2) + 0.25;
  	old_im = (set->mouse_y - WIN_Y) / ((double)WIN_Y) + 0.50;
	i = 0;
	while (++i < set->max && SQR(new_re) + SQR(new_im) <= 4.0)
	{
		old_re = new_re;
	old_im = new_im;
		new_re = SQR(old_re) - SQR(old_im) + pr;
		new_im = 2 * old_re * old_im + pi;
	}
	return (i);
}
*/

int			calc_iters_heart(t_fract *set, int row, int col)
{
	int		i;
	double	new_re;
	double new_im;
	double old_re;
	double old_im;
	double pr;
	double pi;

	pr = 1.5 * (row - WIN_X / 2) / (0.5 * set->zoom * WIN_X) + set->move_x;
	pi = 1.5 * (col - WIN_Y / 2) / (0.5 * set->zoom * WIN_Y) + set->move_y;
	new_re = 0; 
	new_im = 0; 
	i = 0;
	while (i < set->max && pr + pi <= 4)
	{
		 new_re = SQR(pr) - SQR(pi) + pr;
		 new_im = 2 *  pr *  pi + pi;
		i++;
	}
	return (i);
}

void draw_heart(t_fract *set, int row, int rowdist)
 {
  int col;
  int i;
  int temp;
  int pos;
  
  temp = 0;

  while (row < rowdist)
  {
    col = 0;
    while (col++ < WIN_X)
    {
      i = calc_iters_heart(set, row, col);
      pos = (col * 4) + (row * 1000 * 4);
      if (i == set->max)
        set->data[pos] = BLACK;
      else
        set->data[pos] = set->color_arr[i % 16];
    }
    row++;
  }
}

/*
void		draw_jx(void *img_ptr)
{
	int col;
	int row;
 	int i;
 	char *data;
	int *color_arr;
  t_mlx mlx;
  t_fract var;

	color_arr = make_col_arr(set);
	data = mlx_get_data_addr(img_ptr, &mlx.bpp, &mlx.size_line, &mlx.endian);
	row = 0;
  while (row < WIN_X)
  {
    col = -1;
    while (++col < WIN_Y)
    {
    	i = julia_explorer(&var, row, col);
      if (i == 300)
				data[col * 4 + row * WIN_Y * 4] = BLACK;
			else
				data[col * 4 + row * WIN_Y * 4] = color_arr[i % 100];
	}
		row++;
  
  }
}

void init_window_jx(t_fract *set)
{
	set->mlx_ptr = mlx_init();
	set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "Julia Explorer");
	set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
	draw_jx(set->img_ptr);
	mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
	mlx_key_hook(set->win_ptr, deal_key, (void *)0);	
	mlx_loop(set->mlx_ptr);
}*/
