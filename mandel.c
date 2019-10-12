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

void draw_mandel(t_fract *set)
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
      i = calc_iters_man(set, row, col, 64);
      if (i == set->max)
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
void init_window_mandel(t_fract *set)
{
  set->mlx_ptr = mlx_init();
  set->win_ptr = mlx_new_window(set->mlx_ptr, WIN_X, WIN_Y, "MANDELBROT");
  set->img_ptr = mlx_new_image(set->mlx_ptr, WIN_Y, WIN_X);
  set->data =mlx_get_data_addr(set->img_ptr, &(set->mlx_data.bpp), &(set->mlx_data.size_line), &(set->mlx_data.endian));
  set->color_arr = make_col_arr();
  setup_env(set);
  draw_mandel(set);
  mlx_put_image_to_window(set->mlx_ptr,set->win_ptr,set->img_ptr , 0, 0);
  mlx_key_hook(set->win_ptr, deal_key, (void *)0);  
  mlx_mouse_hook(set->win_ptr, mouse_hooks, set);
  mlx_loop(set->mlx_ptr);
}