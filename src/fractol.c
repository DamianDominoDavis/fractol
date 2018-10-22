/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:05:43 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/22 16:41:37 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void		die(void *mlx, void *win, int r)
{
	if (mlx)
	{
		if (win)
			mlx_destroy_window(mlx, win);
		free(mlx);
	}
	exit(r);
}

static int		fdf_key_hook(int key, void *p[])
{
	if (key == 53)
		die(p[0], p[1], 0);
	return (0);
}

static void		hooks(void *mlx, void *win)
{
	mlx_hook(win, 2, 5, fdf_key_hook, (void*[]){mlx, win});
	mlx_string_put(mlx, win, 10, K_H - 30, K_WHITE, "ESC: exit");
	mlx_loop(mlx);
}

t_env	init(int c, char **v)
{
	t_env out;

	out->mlx = mlx_init();
	out->win = mlx_new_window(out->mlx, W_WIDTH, W_HEIGHT, "fractol");
	out->fractal.id = atoi(argv[1])
	
}

int		main(int c, char **v)
{
	t_env e;

	e = init(c,v);
	hooks(e->mlx, e->win);
	return (0);
}
