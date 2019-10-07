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
static	int	calc_iters(t_fract *var, int row, int col)
{
	double	old_re;
	double	old_im;
	double	new_re;
	double	new_im;
	int		i;
	var->max = 300;
	var->move_x = 0;
	var->move_y = 0;
	var->zoom = 1;

	new_re = 1.5 * (row - WIN_X / 2) / (0.5 * var->zoom * WIN_X) + var->move_x;
	new_im = 1.5 * (col - WIN_Y / 2) / (0.5 * var->zoom * WIN_Y) + var->move_y;
	i = -1;
	while (++i < var->max && SQR(new_re) + SQR(new_im) <= 4.0)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = SQR(old_re) - SQR(new_im) + -0.7;
		new_im = 2 * (old_im * old_re) + 0.27015;
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
	t_fract var;

	color_arr = make_col_arr();
	data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	
	int	i;
	int	col;
	int row;

	row = 0;
	while (row < WIN_X)
	{
		col = 0;
		while (++col < WIN_Y)
		{
			i = calc_iters(&var, row, col);
			if (i == 64)
				data[col * 4 + row * (WIN_Y * 4)] = BLACK;
			
				data[col * 4 + row * (WIN_Y * 4)] = color_arr[i % 64];
		}
		row++;
	}
}