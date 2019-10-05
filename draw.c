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
#define WIN_Y 800
#define M_PI        3.14159265358979323846264338327950288  
# define SQR(x)					(x * x)
# define BLACK			0x0


int				deal_key(int key, void *param)
{
	if (key == 53)
	{
		ft_putendl("IT is time to go Bye Bye");
		exit(0);
	}
	return (0);
}

void		*make_col_arr(void)
{
	t_rgb			rgb;
	int				c;
	float			r;
	int				*arr;


	/*rgb.r = 218;
	rgb.g = 219;
	rgb.b = 213;*/
	arr = (int *)malloc(sizeof(int) * 100);
	c = -1;
	r = 0;
	while (c <  100)
	{
		rgb.r = (cos(r) + 1) * 127;
		rgb.g = (sin(r) + 1) * 127;
		rgb.b = (-cos(r) + 1) * 127;
		arr[c] = rgb.b | rgb.g << 4 | rgb.r << 16;
		r += M_PI / 6;
		c++;
	}
	return arr;
} 




int main (int ac, char **av)
{
	int width = WIN_X;
	int height = WIN_Y;
	double zoom = 1.0; 
  	double move_x = -0.5; 
  	double move_y = 0.0; 

	void *mlx_ptr = mlx_init();
	void *win_ptr = mlx_new_window(mlx_ptr, width, height, "julia");
	void *img_ptr = mlx_new_image(mlx_ptr, 2000, 1000);

	draw_ship(img_ptr);
	mlx_put_image_to_window(mlx_ptr,win_ptr,img_ptr , 400, 0);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	
	mlx_loop(mlx_ptr);
	return (0);

}