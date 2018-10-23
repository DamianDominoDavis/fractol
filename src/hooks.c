#include "fractol.h"

static int	loop(t_params *e)
{
	if (e->fractal.id == 1)
	{
		mandelbrot(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img.ptr, 0, 0);
	}
	return (0);
}

static int	key_hook(int key, t_params *e)
{
	if (key == 53)
		die(e->mlx, e->win, 0);
	return (0);
}

void		hooks(t_params *e)
{
	mlx_hook(e->win, 2, 5, key_hook, e);
	mlx_loop_hook(e->mlx, loop, e);
	mlx_loop(e->mlx);
}
