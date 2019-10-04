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

// void		draw_julia(int size, int *color_arr, int *data, int row, int stop)
// {
// 	int	i;
// 	int	col;
// 	double zoom = 1;
// 	double move_x = 0;
// 	double move_y = 0;
// 	int max = 300;
// 	while (row < stop)
// 	{
// 		col = -1;
// 		while (++col < WIN_X)
// 		{
// 			i = calc_iters(zoom, move_x, move_y, max, row, col);
// 			if (i == e->max)
// 				data[col + row * size / 4] = BLACK;
// 			else
// 				data[col + row * size / 4] = color_arr[i % 64];
// 		}
// 		row++;
// 	}
// }
