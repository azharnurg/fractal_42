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
static int calc_iters_man(t_fract *set, int row, int col, double new_re)
{
  double pr; 
  double pi;    
  double old_re;
  double new_im;
  double old_im;
  int i;

  pr = 1.5 * (row - WIN_X / 2) / (0.5 * set->zoom * WIN_X) + set->move_x;
  pi = 1.5 * (col - WIN_Y / 2) / (0.5 * set->zoom * WIN_Y) + set->move_y;
  old_re = 0;
  old_im = 0;
  i = 0;
  while (i++ < set->max && (SQR(old_re) + SQR(old_im)) <= 4.0)
  {
    new_re = SQR(old_re) - SQR(old_im) + pr;
    old_im = 2 * old_re * old_im + pi;
    old_re = new_re;
    
  }
  return (i);
}

void draw_mandel(t_fract *set, int row, int rowdist)
 {
  int col;
  int i;
  int temp;
  
  temp = 0;
  while (row++ < rowdist)
  {
    col = 0;
    while (col++ < WIN_X)
    {
      i = calc_iters_man(set, row, col, temp);
      if (i == set->max)
        set->data[col + row * (set->mlx_data.size_line / 4)] = BLACK;
      else
        set->data[col + row * (set->mlx_data.size_line / 4)] = set->color_arr[i % 64];
    }
  }
}



/*static void setup_env(t_fract *set)
{
  set->zoom = 1;   
  set->move_x = -0.5; 
  set->move_y = 0; 
  set->max = 1024;

}*/
/*void init_window_mandel(t_fract *set)
{
  set->mlx_ptr = mlx_init();
  set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "MANDELBROT");
  set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
  set->data =mlx_get_data_addr(set->img_ptr, &(set->mlx_data.bpp), &(set->mlx_data.size_line), &(set->mlx_data.endian));
  set->color_arr = make_col_arr(set);
  setup_env(set);
  thread(set);
  mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
  mlx_key_hook(set->win_ptr, deal_key, (void *)0);  
  mlx_mouse_hook(set->win_ptr, mouse_hooks, set);
  mlx_loop(set->mlx_ptr);
}*/