/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:24:12 by anurgali          #+#    #+#             */
/*   Updated: 2019/09/23 12:26:29 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define KEY_ESC 53
#define WIN_X 1000
#define WIN_Y 800
#define M_PI        3.14159265358979323846264338327950288  
# define SQR(x)					(x * x)
# define BLACK			0x0


typedef struct	s_rgb
{
	 int r;
	 int g;
	 int b;
}				t_rgb;
typedef struct s_fract
{
	double zoom;
	double move_x;
	double move_y;
	int max;
}			t_fract;


static	int	calc_iters(t_fract *var, int row, int col);
void draw_mandel(void *img_ptr);
void	draw_julia(void *img_ptr);
void		*make_col_arr(void);
void		draw_ship(void *img_ptr);
#endif