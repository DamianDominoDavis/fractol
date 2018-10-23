/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:50:22 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/22 21:59:41 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	loop(t_params *e)
{
	if (e->fractal.id == 1)
	{
		mandelbrot(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	}
	else if (e->fractal.id == 2)
	{
		julia(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	}	
	return (0);
}

static int	key_hook(int key, t_params *e)
{
	if (key == 53)
		die(e->mlx, e->win, 0);
	return (0);
}

void		hooks(t_params *e)
{
	mlx_hook(e->win, 2, 5, key_hook, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
}
