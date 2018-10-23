/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:05:43 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/23 14:00:51 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	init(int c, char **v, t_params *e)
{
	if ((ft_strlen(v[1]) != 1 || !ft_isdigit(v[1][0]))
		|| (c == 3 && (ft_strlen(v[2]) != 1 || !ft_isdigit(v[2][0]))))
		return (-1);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, W_WIDTH, W_HEIGHT, "fractol");
	if (0 >= (e->fractal.id = ft_atoi(v[1])))
		return (-1);
	// e->fractal.gen = (c == 3) ? ft_atoi(v[2]) : 0;
	// if (e->fractal.id > 4 || e->fractal.gen > 1)
	// return (-1);
	e->fractal.zoom = 1.0;
	e->fractal.pos_x = 0.0;
	e->fractal.pos_y = 0.0;
	e->fractal.max_x = 2.4;
	e->fractal.max_y = 1.5;
	e->clic = (t_clic){(int)0,(int)0,(int)0};
	e->img.ptr = mlx_new_image(e->mlx, W_WIDTH, W_HEIGHT);
	e->img.data = mlx_get_data_addr(e->img.ptr, &e->img.bpp, &e->img.size_line,
		&e->img.endian);
	return (0);
}

void		die(void *mlx, void *win, int r)
{
	if (mlx)
	{
		if (win)
			mlx_destroy_window(mlx, win);
		free(mlx);
	}
	exit(r);
}

int			main(int c, char **v)
{
	t_params e;

	if (c > 1 && c < 3 && 0 == init(c, v, &e))
		hooks(&e);
	else
	{
		ft_putstr("usage: fractol id [opt]\n");
		ft_putstr("id:\t[1] Mandelbrot, c = 0 + 0i\n");
		ft_putstr("\t[2] Julia, c = \u03A6-2 + (\u03A6-1)i\n");
		ft_putstr("opt:\tabsolutely useless\n");
	}
	return (0);
}
