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
static	int	calc_iters(double zoom,double move_x, int max, double move_y,  int row, int col)
{
	double	re_temp;
	double	i_temp;
	double	y;
	double	x;
	int		i;

	y = 1.5 * (row - WIN_X / 2) / (0.5 * zoom * WIN_X) + move_x;
	x = 1.5 * (col - WIN_Y / 2) / (0.5 * zoom * WIN_Y) + move_y;
	i = -1;
	while (++i < max && SQR(x) + SQR(y) <= 4.0)
	{
		re_temp = x;
		i_temp = y;
		x = SQR(re_temp) - SQR(i_temp) + (0.7);
		y = 2 * (i_temp * re_temp) + (0.27015);
	}
	return (i);
}

void	draw_julia(void *img_ptr)
{
	char *data;
	int bpp;
	int size_line;
	int endian;
	int *color_arr;

	color_arr = make_col_arr();
	data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	
	int	i;
	int	col;
	int row;

	row = 0;
	while (row < WIN_Y)
	{
		col = 0;
		while (++col < WIN_X)
		{
			i = calc_iters(1.0, 0, 300, 0, row, col);
			if (i == 64)
				data[row + col * size_line / 4] = BLACK;
			
				data[col + row * size_line ] = color_arr[i % 64];
		}
		row++;
	}
}