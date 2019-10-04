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
static int calc_iters_man(double zoom, int max, double move_x, double move_y, int row, int col, double temp)
{
  double pr, pi;    
  double newRe, newIm, oldRe, oldIm;
  zoom = 1; 
  move_x = -0.5; 
  move_y = 0; 
  max = 300;
  
    pr = 1.5 * (row - WIN_X / 2) / (0.5 * zoom * WIN_X) + move_x;
    pi = (col - WIN_Y / 2) / (0.5 * zoom * WIN_Y) + move_y;
    newRe = newIm = oldRe = oldIm = 0; 
    int i = -1;
    while (++i < max && (SQR(newRe) + SQR(newIm)) <= 4.0)
    {
      temp = SQR(oldRe) - SQR(oldIm) + pr;
      newIm = 2 * oldRe * oldIm + pi;
      newRe = temp;
    
    }
    return (i);
}

void draw_mandel(void *img_ptr)
 {
  	double temp;
	int col;
	int row;
 	int i;
 	int bpp;
	int size_line;
	int endian;
 	char *data;
	int *color_arr;
	//color_arr = make_col_arr();
	data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	row = 0;
  while (row < WIN_Y)
  {
    col = -1;
    while (++col < WIN_X)
    {
    	i = calc_iters_man(1.0, 300, -0.5, 0, row, col, temp);
  
      if (i == 300)
				data[col + row * size_line / 4] = BLACK;
			else
				data[col + row * size_line / 4] = color_arr[i % 64];
	}
		row++;
  
  }
}