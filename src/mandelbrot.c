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

void	mandelbrot_init(int x, int y, t_env *e, t_img *c)
{
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;

	min_x = (-e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	max_x = (e->fractal.max_x / e->fractal.zoom) + e->fractal.pos_x;
	min_y = (-e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	max_y = (e->fractal.max_y / e->fractal.zoom) + e->fractal.pos_y;
	c->real = min_x + x * (max_x - min_y) / W_WIDTH;
	c->img = min_y + y * (max_y - min_y) / W_HEIGHT;
}

void	verif_printf(t_env *e, int x, int y, int color)
{
	int	index;

	index = 0;
	if (x >= 0 && y >= 0 && x <= W_WIDTH && y <= W_HEIGHT)
	{
		index = y * e->img.size_line + x * (e->img.bpp / 8);
		e->img.data[index] = color;
		e->img.data[index + 1] = color >> 8;
		e->img.data[index + 2] = color >> 16;
	}
}

int	rgb_to_i(int r, int g, int b)
{
	return ((r << 16 + g) << 8 + b);
}

int		choose_color(int i, t_env *e)
{
	int	tmp;

	tmp = (e->fractal.gen) ? (int)(MAX_IT + e->fractal.zoom / 1000) : MAX_IT;
	if (i == tmp)
		return rgb_to_i(200,190,120);
	else
		return (rgb_to_i(
			sin((float)i / ((float)MAX_IT / 1.5)) * 255,
			sin((float)i / ((float)MAX_IT / 2)) * 255,
			sin((float)i / ((float)MAX_IT / 3.5)) * 255));
}

void	mandelbrot_col(t_env *e, int y, t_img *c)
{
	int x;
	int i;
	int color;
	t_img z;
	t_img tmp;

	x = 0;
	while (x < W_WIDTH)
	{
		mandelbrot_init(x, y, e, c);
		z = Z_BLANK;
		i = 0;
		while (i < (int)(MAX_IT + (e->fractal.zoom / 1000) * e->fractal.gen))
		{
			tmp.img = z.img;
			tmp.real = z.real;
			z.real = tmp.real * tmp.real - tmp.img * tmp.img + c->real;
			z.img = 2 * tmp.real * tmp.img + c->img;
			if ( z.real * z.real + z.img * z.img >= 4)
				break ;
			i++;
		}
		color = choose_color(i, e);
		verif_printf(e, x, y, color);
		x++;
	}
}

void	draw_mandelbrot(t_env *e)
{
	int	y;
	t_img img;

	y = 0;
	while (y < W_HEIGHT)
		mandelbrot_col(e, y++, &img);
}
