/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:05:43 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 20:21:28 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init(int c, char **v, t_params *e)
{
	int		id;
	int		gen;

	if (c < 2)
		return (0);
	id = ft_atoi(v[1]);
	gen = (c == 3) ? ft_atoi(v[2]) : 0;
	if (!((c >= 2 && c <= 3) && (id >= 1 && id <= 3) && (gen <= 1)))
		return (0);
	e->frac = (t_fractal){ft_atoi(v[1]), 1.0, 0, 0, 2.4, 1.5,
		(c == 3) ? ft_atoi(v[2]) : 0};
	e->click = (t_click){1, 0, 0};
	if (!(e->mlx = mlx_init())
		|| !(e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "fractol"))
		|| !(e->img.ptr = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT)))
		die(e, -1);
	e->img.data = mlx_get_data_addr(e->img.ptr, &e->img.bpp, &e->img.size_line,
		&e->img.endian);
	return (1);
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
	ft_putstr((r >= 0) ? " done\n" : " crash\n");
	exit(r);
}

/*
** hook constants from typical /usr/include/X11/X.h
*/
int			main(int c, char **v)
{
	t_params e;

	if (init(c, v, &e))
	{
		ft_putstr("fractol");
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
		ft_putstr("  id: [1] \033[0;34mMandelbrot\033[0m, c = 0+0i\n");
		ft_putstr("      [2] \033[0;32mJulia\033[0m, c = (\u03A6-2)+(\u03A6-1)i\n");
		ft_putstr("      [3] \033[0;31mBurning Ship\033[0m, c = 0+0i\n");
		//ft_putstr("      [4] Newton, c = 0+0i\n");
		ft_putstr("  opt:\tabsolutely useless\n");
	}
	return (0);
}
