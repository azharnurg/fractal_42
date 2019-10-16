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


int calc_iters_man(t_fract *set, int row, int col, double new_re)
{
  double pr; 
  double pi;    
  double old_re;
  double new_im;
  double old_im;
  int i;

  pr = 2.0 * (col - WIN_X / 2) / (0.5 * set->zoom * WIN_X) + set->move_x;
  pi = 2.0 * (row - WIN_Y / 2) / (0.5 * set->zoom * WIN_Y) + set->move_y;
  new_re = (set->mouse_x - WIN_X) / ((double)WIN_X * 2) + 0.25;
  old_im = (set->mouse_y - WIN_Y) / ((double)WIN_Y) + 0.50;
  i = 0;
  while (SQR(new_re) + SQR(old_im) <= 4.0 && i < 42)
  {
    old_re = new_re;
    new_re = SQR(new_re) - SQR(old_im) + pr;
    old_im = (2 * old_im) * old_re + pi;
    i++;
  }
  return (i);
}
/*
static int calc_iters_man(t_fract *set, int row, int col, double new_re)
{
  double pr; 
  double pi;    
  double old_re;
  double new_im;
  double old_im;
  int i;

  pr = 2.0 * (col - WIN_X / 2) / (0.5 * set->zoom * WIN_X) + set->move_x;
  pi = 2.0 * (row - WIN_Y / 2) / (0.5 * set->zoom * WIN_Y) + set->move_y;
  old_re = 0;
  old_im = 0;
  i = 0;
  while (SQR(old_re) + SQR(old_im) <= 4.0 && i < 42)
  {
    old_re = new_re;
    new_re = SQR(new_re) - SQR(old_im) + pr;
    old_im = (2 * old_im) * old_re + pi;
    i++;
  }
  return (i);
}*/

void draw_mandel(t_fract *set, int row, int rowdist)
 {
  int col;
  int i;
  int temp;
  int pos;
  
  temp = 0;
  //printf("PosIndex = %d\n", rowdist);

  while (row < rowdist)
  {
    col = 0;
    while (col++ < WIN_X)
    {
      i = calc_iters_man(set, row, col, temp);
      pos = (col * 4) + (row * 1000 * 4);
      if (i == set->max)
        set->data[pos] = BLACK;
      else
        set->data[pos] = set->color_arr[i % 64];
    }
    row++;
  }
}
/*
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
        set->data[col + row * (set->size_line / 4)] = BLACK;
      else
        set->data[col + row * (set->size_line / 4)] = set->color_arr[i % 16];
    }
  }
}
*/
