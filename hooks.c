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
	if (fract->flag == 0 && x < WIN_X & y < WIN_Y)
	{
		fract->mouse_y = y;
		fract->mouse_x = x;
	}
	draw_julia(fract);
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
	mlx_put_image_to_window(e->mlx_ptr,e->win_ptr,e->img_ptr , 0, 0);
	return (0);
}

int				deal_key(int key, t_fract fractol)
{
	if (key == 53)
	{
		ft_putendl("IT is time to go Bye Bye");
		exit(0);
	}
	else if (keycode == KEY_ANSI_I)
		zoom_in((WIN_WIDTH / 2), (WIN_HEIGHT / 2), fractol);
	else if (keycode == KEY_ANSI_O)
		zoom_out(fractol);
	
	return (0);
}