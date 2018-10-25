/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:05:43 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 14:26:00 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ptest(int c, char **v)
{
	(void)c;
	(void)v;
	return (0);
}

static int	init(int c, char **v, t_params *e)
{
	if (!ft_isdigit(v[1][0]) || (c == 3 && !ft_isdigit(v[2][0])))
		die(e, -1);
	if (0 >= (e->frac.id = ft_atoi(v[1])))
		die(e, -1);
	e->frac.gen = (c == 3) ? ft_atoi(v[2]) : 0;
	if (e->frac.id > IDMAX || e->frac.gen > 1)
		die(e, -1);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "fractol");
	e->frac = (t_fractal){e->frac.id, 1.0, 0, 0, 2.4, 1.5, e->frac.gen};
	e->clic = (t_clic){0, 0, 0};
	e->img.ptr = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT);
	e->img.data = mlx_get_data_addr(e->img.ptr, &e->img.bpp, &e->img.size_line,
		&e->img.endian);
	return (0);
}

void		die(t_params *e, int r)
{
	if (e->mlx)
	{
		if (e->win)
			mlx_destroy_window(e->mlx, e->win);
		if (e->img.ptr)
			mlx_destroy_image(e->mlx, e->img.ptr);
		free(e->mlx);
	}
	exit(r);
}

/*
** hook constants from typical /usr/include/X11/X.h
*/
int			main(int c, char **v)
{
	t_params e;

	if (c > 1 && c < 3 && 0 == init(c, v, &e))
	{
		mlx_hook(e.win, 6, (1L<<6), motion_notify, &e);
		mlx_hook(e.win, 4, (1L<<2), button_press, &e);
		mlx_hook(e.win, 5, (1L<<3), button_release, &e);
		mlx_hook(e.win, 2, 5, key_press, &e);
		mlx_loop_hook(e.mlx, loop, &e);
		mlx_loop(e.mlx);
	}
	else
	{
		ft_putstr("usage: fractol id [opt]\n");
		ft_putstr("id:\t[1] Mandelbrot, c = 0+0i\n");
		ft_putstr("\t[2] Julia, c = (\u03A6-2)+(\u03A6-1)i\n");
		ft_putstr("\t[3] Burning Ship, c = 0+0i\n");
		//ft_putstr("\t[4] Newton, c = 0+0i\n");
		ft_putstr("opt:\tabsolutely useless\n");
	}
	return (0);
}
