/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:47:03 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/25 21:08:48 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	button_press(int keycode, int x, int y, t_params *e)
{
	float	direction;

	if (keycode == 5 || keycode == 4)
	{
		direction = (keycode == 4) ? 0.8 : 1.25;
		e->frac.zoom *= direction;
		e->frac.pos_x += ((x - (W_WIDTH / 2)) / (W_WIDTH / 2)) / e->frac.zoom;
		e->frac.pos_y += ((y - (W_HEIGHT / 2)) / (W_HEIGHT / 2)) / e->frac.zoom;
	}
	return (0);
}

int	button_release(int keycode, int x, int y, t_params *e)
{
	if (keycode == 1)
		e->click = (t_click){e->click.active, x, y};
	return (0);
}

int	motion_notify(int x, int y, t_params *e)
{
	if (e->click.active)
		e->click = (t_click){e->click.active, x, y};
	return (0);
}

int	loop(t_params *e)
{
	static void (**fractals)(t_params*);

	fractals = (void(*[IDMAX + 1])(t_params*))
		{NULL, mandelbrot, julia, burningship};
	fractals[e->frac.id](e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	if (e->inst)
	{
		mlx_string_put(e->mlx, e->win, 10, 10, rgb(255, 255, 255),
			"[Esc] die");
		mlx_string_put(e->mlx, e->win, W_WIDTH - 100, 10, rgb(255, 255, 255),
			"[0-9] dye");
		mlx_string_put(e->mlx, e->win, 10, W_HEIGHT - 30, rgb(255, 255, 255),
			"[' '] blind");
		if (e->frac.id == 2)
			mlx_string_put(e->mlx, e->win, W_WIDTH - 110, W_HEIGHT - 30,
				rgb(255, 255, 255), (e->click.active) ? "['U'] stop" :
				"['U'] go");
	}
	return (0);
}

int	key_press(int key, t_params *e)
{
	if (key == 53)
		die(e, 0);
	if (key == 32)
		e->click.active = (e->click.active) ? 0 : 1;
	if (key == 49)
		e->inst = (e->inst) ? 0 : 1;
	if (key >= 82 && key <= 92 && key != 90)
		e->palette = (t_palette[10]){
			(t_palette){0, 1, 1, 1, 255, 255, 255},
			(t_palette){1644876, 1.5, 2, 3.5, 255, 255, 255},
			(t_palette){16992805, 3.5, 1.5, 2, 255, 255, 255},
			(t_palette){16992805, 2, 3.5, 1.5, 255, 255, 255},
			(t_palette){0, 5, 3, 1, 255, 255, 0},
			(t_palette){0, 1, 5, 3, 255, 0, 255},
			(t_palette){0, 3, 1, 5, 0, 255, 255},
			(t_palette){rgb(75, 163, 223), 3, 2, 2, 255, 255, 0},
			(t_palette){rgb(247, 62, 103), 1, 4, 2, 0, 255, 0},
			(t_palette){rgb(113, 188, 167), 1, 3, 5, 255, 255, 255}
		}[(key > 90) ? key - 83 : key - 82];
		;
	return (0);
}
