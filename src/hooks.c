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

static int	loop(t_params *e)
{
	void (**fractals)(t_params*);

	fractals = (void(*[IDMAX + 1])(t_params*)){NULL, mandelbrot, julia, burningship};//, newton};
	fractals[e->frac.id](e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	return (0);
}

static int	key_hook(int key, t_params *e)
{
	if (key == 53)
		die(e->mlx, e->win, 0);
	if (key == 32)
		e->clic.active = e->clic.active ? 0 : 1;
	return (0);
}

void		hooks(t_params *e)
{
	mlx_hook(e->win, 2, 5, key_hook, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
}
