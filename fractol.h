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
# include <pthread.h>
# define KEY_ESC 53

#define WIN_X 1000
#define WIN_Y 1000
# define ZOOM_SCALE		0.90
#define M_PI        3.14159265358979323846264338327950288  
# define SQR(x)					(x * x)
# define BLACK			0x0

//Mouse code
# define M_LCLICK		0x02
# define M_RCLICK		0x01
# define M_UPSCRLL		0x04
# define M_DWNSCRLL		0x05

//key code
# define KEY_ANSI_I		34
# define KEY_ANSI_O		31

# define NEW_XOFF(x, zoom)		0.15 * ((x - WIN_X / 2) / (WIN_X / 2 / zoom))
# define NEW_YOFF(y, zoom)		0.15 * ((y - WIN_Y / 2) / (WIN_Y / 2 / zoom))

typedef struct	s_mlx
{
	int bpp;
	int size_line;
	int endian;
}				t_mlx;

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
	double pr;
	double pi;
	double				mouse_x;
	double				mouse_y;
	int max;
	int flag;
	int					*color_arr;
	int 	fract_num;
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;
	void *param;
	char *data;
	t_rgb	rgb;
	int bpp;
	int size_line;
	int endian;
	//t_mlx	mlx_data;
}			t_fract;

typedef struct 		s_thread
{
	t_fract *fract;
	int row;
	int rowdist;
}					t_thread;

static	int	calc_iters(t_fract *var, int row, int col);
void draw_mandel(t_fract *set, int row, int rowdist);
void	draw_julia(t_fract *set, int row, int rowdist);
void		draw_ship(t_fract *set, int row, int rowdist);
void init_window_ship(t_fract *set);
void init_window_mandel(t_fract *set);
void init_window_julia(t_fract *set);
void		make_col_arr(t_fract *set);
int				julia_mouse_hook(int x, int y, t_fract *fract);
int				mouse_hooks(int button, int x, int y, t_fract *e);
int				deal_key(int key, t_fract *e);
void init_window_jx(t_fract *set);
void thread(t_fract *f);
void choose_fract(t_fract *set);
void setup_env(t_fract *set);


#endif