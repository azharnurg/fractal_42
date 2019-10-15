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

int				julia_mouse_hook(int x, int y, t_fract *set)
{
	if (set->flag == 0 && x < WIN_X & y < WIN_Y)
	{
		set->mouse_y = y;
		set->mouse_x = x;
			}
	choose_fract(set);
	return (0);
}


static	void	zoom_in(double x, double y, t_fract *set)
{
	printf("Zoom In\n");
	set->move_x -= NEW_XOFF(x,set->zoom);
	set->move_y -= NEW_YOFF(y, set->zoom);
	printf("moveXY_Before: [%f,%f]\n", set->move_x,set->move_y);

	set->zoom /= ZOOM_SCALE;
	set->move_x += NEW_XOFF(x, set->zoom);
	set->move_y += NEW_YOFF(y, set->zoom);
	printf("moveXY_After: [%f,%f]\n", set->move_x,set->move_y);

	set->max--;
}

static	void	zoom_out(double x, double y, t_fract *set)
{
	float xOff = 0;
	float yOff = 0;

	printf("Zoom out\n");
	printf("moveXY_Before: [%f,%f]\n", set->move_x,set->move_y);

	xOff = NEW_XOFF(x, set->zoom);
	yOff = NEW_YOFF(y, set->zoom);
	printf("x/yOff = [%f,%f]\n",xOff,yOff );
	set->move_x += xOff;
	set->move_y += yOff;
	set->zoom *= ZOOM_SCALE;
	set->move_x -= NEW_XOFF(x, set->zoom);
	set->move_y -= NEW_YOFF(y, set->zoom);
	printf("moveXY_After: [%f,%f]\n", set->move_x,set->move_y);

	set->max++;
}
int				mouse_hooks(int button, int x, int y, t_fract *set)
{
	printf("\nX = %d\nY = %d\n", x, y);
	if (button == M_UPSCRLL || button == M_LCLICK)
		zoom_in(x, y, set);
	else if (button == M_DWNSCRLL || button == M_RCLICK)
		zoom_out(x, y, set);
	choose_fract(set);
	return (0);
}

int				deal_key(int key, t_fract *e)
{

	printf("I am pressing %d\n", key);

	if (key == 53)
	{
		ft_putendl("IT is time to go Bye Bye");
		exit(0);
	}

	return (0);
}