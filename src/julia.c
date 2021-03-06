/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 22:19:59 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/25 18:28:17 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	z_init(int x, int y, t_params *e, t_complex *c)
{
	t_complex	z;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;

	min_x = (-e->frac.max_x / e->frac.zoom) + e->frac.pos_x;
	max_x = (e->frac.max_x / e->frac.zoom) + e->frac.pos_x;
	min_y = (-e->frac.max_y / e->frac.zoom) + e->frac.pos_y;
	max_y = (e->frac.max_y / e->frac.zoom) + e->frac.pos_y;
	z.r = min_x + x * (max_x - min_x) / W_WIDTH;
	z.i = min_y + y * (max_y - min_y) / W_HEIGHT;
	c->r = (0.5 * e->click.x) / (long double)W_WIDTH;
	c->i = (0.5 * e->click.y) / (long double)W_HEIGHT;
	return (z);
}

static int			z_iter(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.i = z->i;
	tmp.r = z->r;
	z->r = tmp.r * tmp.r - tmp.i * tmp.i + c->r;
	z->i = 2 * tmp.r * tmp.i + c->i;
	return ((int)((z->r * z->r + z->i * z->i >= 4)));
}

void				julia(t_params *e)
{
	int			i;
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			z = z_init(x, y, e, &c);
			i = -1;
			while (++i < MAX_IT)
				if (z_iter(&z, &c))
					break ;
			iwrite(e, x, y, color(i, e->palette));
		}
	}
}
