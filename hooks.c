/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurgali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 19:17:57 by anurgali          #+#    #+#             */
/*   Updated: 2019/10/06 19:18:17 by anurgali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				julia_mouse_hook(int x, int y, t_fract *fract)
{
	void *img_ptr;
	if (fract->flag == 0 && x < WIN_X & y < WIN_Y)
	{
		fract->mouse_y = y;
		fract->mouse_x = x;
	}
	draw_julia(img_ptr);
	return (0);
}

static	void	zoom_out(int x, int y, t_fract *fract)
{
fract->move_x -= NEW_XOFF(x,fract->zoom);
	fract->move_y -= NEW_YOFF(y, fract->zoom);
	fract->zoom /= ZOOM_SCALE;
	fract->move_x += NEW_XOFF(x, fract->zoom);
	fract->move_y += NEW_YOFF(y, fract->zoom);
	fract->max--;
}

static	void	zoom_in(int x, int y, t_fract *e)
{
	e->move_x += NEW_XOFF(x, e->zoom);
	e->move_y += NEW_YOFF(y, e->zoom);
	e->zoom *= ZOOM_SCALE;
	e->move_x -= NEW_XOFF(x, e->zoom);
	e->move_y -= NEW_YOFF(y, e->zoom);
	e->max++;
}
int				mouse_hooks(int button, int x, int y, t_fract *e)
{
	if (button == M_UPSCRLL || button == M_LCLICK)
		zoom_in(x, y, e);
	else if (button == M_DWNSCRLL || button == M_RCLICK)
		zoom_out(x, y, e);
	draw_julia(e);
	return (0);
}