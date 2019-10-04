/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:19:18 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/02 17:20:08 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define WIN_X 1000
#define WIN_Y 1000
#define M_PI        3.14159265358979323846264338327950288  
# define SQR(x)					(x * x)
# define BLACK			0x0



static	int	calc_iters(double zoom,double move_x, int max, double move_y,  int row, int col)
{
	double	re_temp;
	double	i_temp;
	double	y;
	double	x;
	int		i;

	y = 1.5 * (row - WIN_X / 2) / (0.5 * zoom * WIN_X) + move_y;
	x = 1.5 * (col - WIN_Y / 2) / (0.5 * zoom * WIN_Y) + move_x;
	i = -1;
	while (++i < max && SQR(x) + SQR(y) <= 4.0)
	{
		re_temp = x;
		i_temp = y;
		x = SQR(re_temp) - SQR(i_temp) + (-0.7);
		y = 2 * (i_temp * re_temp) + (0.27015);
	}
	return (i);
}


int				deal_key(int key, void *param)
{
	if (key == 53)
	{
		ft_putendl("IT is time to go Bye Bye");
		exit(0);
	}
	return (0);
}

int		*make_col_arr(void)
{
	t_rgb			rgb;
	int				c;
	float			r;
	int				*arr;


	/*rgb.r = 218;
	rgb.g = 219;
	rgb.b = 213;*/
	arr = (int *)malloc(sizeof(int) * 64);
	c = -1;
	r = 0;
	while (c <  64)
	{
		rgb.r = (cos(r) + 1) * 127;
		rgb.g = (sin(r) + 1) * 127;
		rgb.b = (-cos(r) + 1) * 127;
		arr[c] = rgb.b | rgb.g << 4 | rgb.r << 16;
		r += M_PI / 60;
		c++;
	}
	return arr;
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
		col = -1;
		while (++col < WIN_X)
		{
			i = calc_iters(1.0, 0, WIN_X, 0, row, col);
			
				data[col + row * size_line] = color_arr[i % 64];
		}
		row++;
	}
}




int main ()
{
	int width = WIN_X;
	int height = WIN_Y;
	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, width, height, "julia");
	void *img_ptr = mlx_new_image(mlx_ptr, width, height);

	draw_julia(img_ptr);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_put_image_to_window(mlx_ptr,win_ptr,img_ptr , 0, 0);
	mlx_loop(mlx_ptr);
	return (0);

}