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


#define M_PI        3.14159265358979323846264338327950288  
# define SQR(x)					(x * x)
# define BLACK			0x0


void		*make_col_arr(void)
{
	t_rgb			rgb;
	int				c;
	float			r;
	int				*arr;

	arr = (int *)malloc(sizeof(int) * 100);
	c = -1;
	r = 0;
	while (c <  100)
	{
		rgb.r = (-cos(r) + 1) * 10;
		rgb.g = (sin(r) + 1) * 120;
		rgb.b = (cos(r) + 1) * 10;
		arr[c] = rgb.b << 16 | rgb.g << 4 | rgb.r << 0x10;
		r += M_PI / 2;
		c++;
	}
	return arr;
} 
