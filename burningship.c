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
	var->zoom = 1; 
  var->move_x = -0.5; 
  var->move_y = 0; 
  var->max = 300;

	new_re = 0;
	new_im = 0;
	pr = 2.0 * (col - WIN_X / 2) / (0.5 * var->zoom * WIN_X) + var->move_x;
	pi = 2.0 * (row - WIN_Y / 2) / (0.5 * var->zoom * WIN_Y) + var->move_y;
	i = -1;
	while (SQR(new_re) + SQR(new_im) <= 4.0 && ++i < var->max)
	{
		//old_re = new_re;
		old_re = SQR(new_re) - SQR(new_im) + pr;
		new_im = 2 * fabs(new_re * new_im) + pi;
		new_re = old_re;
	}
	return (i);
}

void		draw_ship(void *img_ptr)
{
	int		i;
	int		col;
	char *data;
	int bpp;
	int size_line;
	int *color_arr;
	int row;
	int max = 300;
	int endian;
	t_fract *var;
	t_rgb rgb;
	int color;
	color_arr = make_col_arr();

	data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	row = 0;
	while (row < WIN_X)
	{
		col = -1;
		while (++col < WIN_Y)
		{
			i = calc_iters_b(var, row, col);
			if (i == max)
				data[col * 4 + row * WIN_Y * 4] = BLACK;
			else
				data[col * 4 + row * WIN_Y * 4] = color_arr[i % 64];
		}
		row++;
	}
}