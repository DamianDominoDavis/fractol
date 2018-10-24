/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:50:22 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 14:21:44 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	button_press(int keycode, int x, int y, t_params *e)
{
	float	direction;

	if (keycode == 5 || keycode == 4)
	{
		direction = keycode == 4 ? 0.5 : 2.0;
		e->frac.zoom *= direction;
		e->frac.pos_x += ((x - (W_WIDTH / 2)) / (W_WIDTH / 2)) / e->frac.zoom;
		e->frac.pos_y += (y - (W_HEIGHT / 2) / (W_HEIGHT / 2)) / e->frac.zoom;
	}
	return (0);
}

int	button_release(int keycode, int x, int y, t_params *e)
{
	if (keycode == 1)
		e->clic = (t_clic){x, y, e->clic.active};
	return (0);
}

int	motion_notify(int x, int y, t_params *e)
{
	if (!e->clic.active)
		e->clic = (t_clic){x, y, e->clic.active};
	return (0);
}

int	loop(t_params *e)
{
	void (**fractals)(t_params*);

	fractals = (void(*[IDMAX + 1])(t_params*))
		{NULL, mandelbrot, julia, burningship};//, newton};
	fractals[e->frac.id](e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	return (0);
}

int	key_press(int key, t_params *e)
{
	if (key == 53)
		die(e->mlx, e->win, 0);
	if (key == 32)
		e->clic.active = e->clic.active ? 0 : 1;
	return (0);
}

