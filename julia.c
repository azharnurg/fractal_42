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
static	int	calc_iters(t_fract *set, int row, int col)
{
	double	old_re;
	double	old_im;
	double	new_re;
	double	new_im;
	int		i;

	new_re = 1.5 * (row - WIN_X / 2) / (0.5 * set->zoom * WIN_X) + set->move_x;
	new_im = 1.5 * (col - WIN_Y / 2) / (0.5 * set->zoom * WIN_Y) + set->move_y;
	i = 0;
	while (i++ < set->max && SQR(new_re) + SQR(new_im) <= 4.0)
	{
		old_re = new_re;
		old_im = new_im;
		new_re = SQR(old_re) - SQR(new_im) + (set->mouse_x * 4.0 / WIN_X - 2.0);
		new_im = 2 * (old_im * old_re) + (set->mouse_y * 4.0 / WIN_Y - 2.0);
	}
	return (i);
}

void	draw_julia(t_fract *set, int row, int rowdist)
{
	int	i;
	int	col;

	row = 0;
	while (row++ < rowdist)
	{
		col = 0;
		
		while (++col < WIN_X)
		{
			i = calc_iters(set, row, col);
			if (i == set->max)
				set->data[col + row * (set->mlx_data.size_line / 4)] = BLACK;
			else
				set->data[col + row * (set->mlx_data.size_line / 4)] = set->color_arr[i % 100];
		}
	}
}
