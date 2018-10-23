/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 22:19:59 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/22 22:33:40 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	julia_init(int x, int y, t_params *e, t_complex *c)
{
	t_complex		z;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;

	min_x = (-e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	max_x = (e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	min_y = (-e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	max_y = (e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	z.real = min_x + (max_x - min_x) / W_WIDTH * (x);
	z.img = min_y + (max_y - min_y) / W_HEIGHT * (y);
	c->real = (e->clic.x * 0.5) / (long double)W_WIDTH;
	c->img = (e->clic.y * 0.5) / (long double)W_HEIGHT;
	return (z);
}

static void			z_iter(t_complex *z, t_complex *c)
{
	t_complex tmp;

	tmp.i = z->i;
	tmp.r = z->r;
	z->r = tmp.r * tmp.r - tmp.i * tmp.i + c->r;
	z->i = 2 * tmp.r * tmp.i + c->i;
}

static int			color(int i)
{
	int			color;

	if (i == MAX_IT)
		color = rgb_to_i(240, 230, 10);
	else
		color = rgb_to_i(sin((float)i / ((float)MAX_IT / 2)) * 255,\
		sin((float)i / ((float)MAX_IT / 3.5)) * 255, 0);
	return (color);
}

void				julia(t_params *e)
{
	int			i;
	int			x;
	int			y;
	t_complex		z;
	t_complex		c;
	
	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			z = z_init(x, y, e, c);
			i = -1;
			while (++i < MAX_IT)
			{
				z_iter(&z, &c);
				if (z.real * z.real + z.img * z.img >= 4)
					break ;
			}
			iwrite(e, x, y, color(i));
		}
	}
}
