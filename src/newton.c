/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:37:04 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/23 19:05:58 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	c_init(int x, int y, t_params *e, t_complex *c)
{
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;

	min_x = (-e->frac.max_x / e->frac.zoom) + e->frac.pos_x;
	max_x = (e->frac.max_x / e->frac.zoom) + e->frac.pos_x;
	min_y = (-e->frac.max_y / e->frac.zoom) + e->frac.pos_y;
	max_y = (e->frac.max_y / e->frac.zoom) + e->frac.pos_y;
	c->r = min_x + x * (max_x - min_y) / W_WIDTH;
	c->i = min_y + y * (max_y - min_y) / W_HEIGHT;
}

static int	z_iter(t_complex *z, t_complex *c)
{
	t_complex	tmp;

	tmp.i = z->i;
	tmp.r = z->r;
	z->r = tmp.r * tmp.r * tmp.r - 3 * tmp.r * tmp.i * tmp.i - 1 + c->i;
	z->i = 3 * tmp.r * tmp.r * tmp.i - tmp.i * tmp.i * tmp.i + c->r;
	return ((int)((z->r * z->r + z->i * z->i >= 4)));
}

static int	color(int i, t_params *e)
{
	int	tmp;

	tmp = (e->frac.gen) ? (int)(MAX_IT + e->frac.zoom / 1000) : MAX_IT;
	if (i == tmp)
		return (rgb_to_i(25, 25, 76));
	else
		return (rgb_to_i(
			sin((float)i / ((float)MAX_IT / 1.5)) * 255,
			sin((float)i / ((float)MAX_IT / 2)) * 255,
			sin((float)i / ((float)MAX_IT / 3.5)) * 255));
}

void		newton(t_params *e)
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
			c_init(x, y, e, &c);
			z = (t_complex){(long double)0, (long double)0};
			i = -1;
			while (++i < (int)(MAX_IT + (e->frac.zoom / 1000) * e->frac.gen))
				if (z_iter(&z, &c))
					break ;
			iwrite(e, x, y, color(i, e));
		}
	}
}
