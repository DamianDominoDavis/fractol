/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:37:04 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/22 16:28:32 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	c_init(int x, int y, t_params *e, t_complex *c)
{
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;

	min_x = (-e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	max_x = (e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	min_y = (-e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	max_y = (e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	c->r = min_x + x * (max_x - min_y) / W_WIDTH;
	c->i = min_y + y * (max_y - min_y) / W_HEIGHT;
}

static void		z_iter(t_complex *z, t_complex *c)
{
	t_complex tmp;

	tmp.i = z->i;
	tmp.r = z->r;
	z->r = tmp.r * tmp.r - tmp.i * tmp.i + c->r;
	z->i = 2 * tmp.r * tmp.i + c->i;
}

static int	color(int i, t_params *e)
{
	int	tmp;

	(void)e;
	//tmp = (e->fractal.gen) ? (int)(MAX_IT + e->fractal.zoom / 1000) : MAX_IT;
	tmp = MAX_IT;
	if (i == tmp)
		return C_GOLD;
	else
		return (rgb_to_i(
			sin((float)i / ((float)MAX_IT / 1.5)) * 255,
			sin((float)i / ((float)MAX_IT / 2)) * 255,
			sin((float)i / ((float)MAX_IT / 3.5)) * 255));
}

void	mandelbrot(t_params *e)
{
	int i;
	int x;
	int	y;
	t_complex z;
	t_complex c;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			c_init(x, y, e, &c);
			z = (t_complex){(long double)0, (long double)0};
			i = -1;
			while (++i < (int)(MAX_IT + e->fractal.zoom / 1000)) //while (i < (int)(MAX_IT + (e->fractal.zoom / 1000) * e->fractal.gen))
			{
				z_iter(&z, &c);
				if (z.r * z.r + z.i * z.i >= 4)
					break ;
			}
			iwrite(e, x, y, color(i, e));
		}
	}
}
