#include <unistd.h>

size_t	ft_strlen(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr++) ;
	return (ptr - str - 1);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
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
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-') ? -1 : 1;
	if (*str == '\0')
		return ((int)(sign * 0));
	while (*str && ft_isdigit(*str))
		out = out * 10 + *str++ - '0';
	return ((int)(out * sign));
}
