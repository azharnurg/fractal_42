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





void *run_fract(void *par)
{
	t_thread *t;

	t = (t_thread*)par;
	if (t->fract->fract_num == 1)
		draw_mandel(t->fract, t->row, t->rowdist);
	if (t->fract->fract_num == 2)	
		draw_julia(t->fract, t->row, t->rowdist);
	if (t->fract->fract_num == 3)
		draw_ship(t->fract, t->row, t->rowdist);
		return NULL;
}

void thread(t_fract *set)
{
	int			count = 10;
	pthread_t	thread[count];
	t_thread	t[count];
	int			i;
	int			rowdist;

	i = 0;
	rowdist = WIN_Y / count;
	while (i < count)
	{
		t[i].fract = set;
		t[i].row = rowdist * i;
		if (i + 1 == count)
			t[i].rowdist = WIN_Y;
		else 
			t[i].rowdist = t[i].row + rowdist;
		pthread_create(&thread[i], NULL, run_fract, &t[i]);
		i++;
	}
	i = 0;
	while (i++ < count)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(set->mlx_ptr, set->win_ptr, \
								set->img_ptr, 0, 0);
}
