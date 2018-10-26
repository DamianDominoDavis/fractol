/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:57:21 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/25 21:35:57 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

# define W_WIDTH (int)800
# define W_HEIGHT (int)600
# define MAX_IT (int)150
# define IDMAX (int)3

typedef struct	s_fractal
{
	int			id;
	float		zoom;
	float		pos_x;
	float		pos_y;
	double		max_x;
	double		max_y;
}				t_fractal;

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_click
{
	int			active;
	int			x;
	int			y;
}				t_click;

typedef struct	s_palette
{
	int			k;
	long double	r;
	long double	g;
	long double	b;
	int			rm;
	int			gm;
	int			bm;
}				t_palette;

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	t_fractal	frac;
	t_image		img;
	t_click		click;
	int			inst;
	t_palette	palette;
}				t_params;

typedef struct	s_complex
{
	long double	i;
	long double	r;
}				t_complex;

/*
**	main.c
*/
void			die(t_params *e, int r);
void			hooks(t_params *e);

/*
**	<fractal>.c
*/
void			mandelbrot(t_params *e);
void			julia(t_params *e);
void			burningship(t_params *e);

/*
**	util.c
*/
void			ft_putstr(const char *str);
int				ft_atoi(const char *str);
void			iwrite(t_params *e, int x, int y, int color);
int				rgb(int r, int g, int b);
int				color(int i, t_palette p);

/*
**	hooks.c
*/
int				button_press(int keycode, int x, int y, t_params *e);
int				button_release(int keycode, int x, int y, t_params *e);
int				motion_notify(int x, int y, t_params *e);
int				loop(t_params *e);
int				key_press(int key, t_params *e);

#endif
