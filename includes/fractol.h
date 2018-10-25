/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:57:21 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 14:24:22 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdlib.h>
# include "mlx.h"

# define W_WIDTH (int)700
# define W_HEIGHT (int)500
# define MAX_IT (int)60
# define C_WHITE (int)16777215
# define C_GOLD (int)-939475336
# define C_NAVY (int)1644876
# define C_WATERMELON (int)16992805
# define IDMAX (int)3

typedef struct	s_fractal
{
	int			id;
	float		zoom;
	float		pos_x;
	float		pos_y;
	double		max_x;
	double		max_y;
	int			gen;
}				t_fractal;

typedef struct	s_clic
{
	int			active;
	int			x;
	int			y;
}				t_clic;

typedef struct	s_image
{
	void		*ptr;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_image;

typedef struct	s_complex
{
	long double	i;
	long double	r;
}				t_complex;

typedef struct	s_params
{
	void		*mlx;
	void		*win;
	t_fractal	frac;
	t_image		img;
	t_clic		clic;
}				t_params;

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
//void			newton(t_params *e);

/*
**	ft.c
*/
size_t			ft_strlen(char *str);
void			ft_putstr(char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(char c);

/*
**	util.c
*/
void			iwrite(t_params *e, int x, int y, int color);
int				rgbint(int r, int g, int b);

/*
**	hooks.c
*/
int				button_press(int keycode, int x, int y, t_params *e);
int				button_release(int keycode, int x, int y, t_params *e);
int				motion_notify(int x, int y, t_params *e);
int				loop(t_params *e);
int				key_press(int key, t_params *e);


#endif
