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
#include <pthread.h>

#define M_PI        3.14159265358979323846264338327950288  
# define SQR(x)					(x * x)
# define BLACK			0x0


void		*make_col_arr(t_fract *set)
{
	int				c;
	float			r;

	set->color_arr = (int *)malloc(sizeof(int) * set->max);
	c = 0;
	r = 0;
	while (c++ <  set->max)
	{
		set->rgb.r = (cos(r) + 1) * 120;
		set->rgb.g = (sin(r) + 1) * 120;
		set->rgb.b = (-cos(r) + 1) * 120;
		set->color_arr[c] = set->rgb.b << 16 | set->rgb.g << 4 | set->rgb.r << 0x10;
		r += M_PI / set->max;
	}
	return NULL;
} 

void *run_fract(void *par)
{
	t_thread *t;

	t = (t_thread*)par;
	if (t->fract->fract_num == 1)
		draw_mandel(t->fract, t->row, t->rowdist);
	if (t->fract->fract_num == 2)	
		draw_julia(t->fract, t->row, t->rowdist);
	/*if (t->fract->fract_num == 3)	
		draw_ship(t->fract, t->row, t->rowdist);*/
		return ((void *)t);
}

void thread(t_fract *set)
{
	int			count = 16;
	pthread_t	thread[count];
	t_thread	t[count];
	int			i;
	int			rowdist;

	i = 0;
	rowdist = WIN_Y / count;
	while (i++ < count)
	{
		t[i].fract = set;
		t[i].row = rowdist * i;
		if (i + 1 == count)
			t[i].rowdist = WIN_Y;
		else 
			t[i].rowdist = t[i].row + rowdist;
		pthread_create(&thread[i], NULL, run_fract, &t[i]);
	}
	i = 0;
	while (i++ < count)
		pthread_join(thread[i], NULL);
}
