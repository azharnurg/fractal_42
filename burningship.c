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
	double	y;
	double	x;
	double	cr;
	double	ci;
	int		i;
	int temp;
	var->zoom = 1; 
  var->move_x = -0.5; 
  var->move_y = 0; 
  var->max = 300;

	y = 0;
	x = 0;
	cr = 2.0 * (col - WIN_X / 2) / (0.5 * var->zoom * WIN_X) + var->move_x;
	ci = 2.0 * (row - WIN_Y / 2) / (0.5 * var->zoom * WIN_Y) + var->move_y;
	i = -1;
	while (SQR(x) + SQR(y) <= 4.0 && ++i < var->max)
	{
		temp = SQR(x) - SQR(y) + cr;
		y = 2 * fabs(x * y) + ci;
		x = temp;
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
				data[col + row * size_line / 4] = BLACK;
			else
				data[col + row * size_line ] = color_arr[i % 64];
		}
		row++;
	}
}