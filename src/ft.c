/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:50:22 by cbrill            #+#    #+#             */
/*   Updated: 2018/10/24 14:18:09 by cbrill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*str)
		str++;
	return (str - s);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
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
	while (*str && ft_isdigit(*str))
		out = out * 10 + *str++ - '0';
	return ((int)(out * sign));
}
