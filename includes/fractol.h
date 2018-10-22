/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:57:21 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/22 16:41:38 by cbrill           ###   ########.fr       */
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
# define C_WHITE ((int)16777215)
# define C_GOLD (int)
# define Z_BLANK (t_img){(long double)0,(long double)0}

typedef struct s_fractal
{
	int		id;
	float	zoom;
	float	pos_x;
	float	pos_y;
	double	max_x;
	double	max_y;
	int		gen;
}	t_fractal;

typedef struct s_image
{
	//void	*ptr;
	char	*data;
	int		bpp;
	int		size_line;
	//int	endian;
}	t_img;

typedef struct s_img
{
	long double img;
	long double real;
}	t_img;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_fractal	fractal;
	t_img		img;

}	t_env;

#endif
