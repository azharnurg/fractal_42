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

typedef struct	s_rgb
{
	 int r;
	 int g;
	 int b;
}				t_rgb;


static	int	calc_iters(double zoom,double move_x, int max, double move_y,  int row, int col);
#endif