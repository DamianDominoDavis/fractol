/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:50:22 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 14:19:04 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iwrite(t_params *e, int x, int y, int color)
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

int		rgbint(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}
