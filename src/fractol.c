/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FRACTOL.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:05:43 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/19 18:10:17 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int				main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = NULL;
	if (mlx)
		win = mlx_new_window(mlx, K_W, K_H, "fractol");
	else die(mlx, win, -1);
	hooks(mlx, win);

	return (0);
}
