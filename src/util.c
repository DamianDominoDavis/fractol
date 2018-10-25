/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:50:22 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 20:24:09 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr(const char *s)
{
	const char	*p;

	p = s;
	while (*p)
		p++;
	write(1, s, p - s);
}

int		ft_atoi(const char *str)
{
	long	out;
	long	sign;

	out = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' || *str
		== '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	if (*str == '\0')
		return ((int)(sign * 0));
	while (*str && *str >= '0' && *str <= '9')
		out = out * 10 + *str++ - '0';
	return ((int)(out * sign));
}

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

int		rgbint(const int r, const int g, const int b)
{
	return ((r << 16) + (g << 8) + b);
}
