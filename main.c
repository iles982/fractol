/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:00:53 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/16 10:14:52 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_e *data;

	if (ac != 2)
	{
		ft_putstr("Try to use 'mandelbrot', 'mandelbar', 'burning_ship',");
		ft_putstr(" or 'julia'\n");
		exit(0);
	}
	if (!(data = (t_e *)malloc(sizeof(t_e))))
		return (-1);
	mlx_win_init(data);
	get_first_data(av[1], data);
	fract_init(data);
	mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
	mlx_hook(data->win, 17, 0L, exit_cl, NULL);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_loop(data->mlx);
	return (0);
}

void	fract_init(t_e *data)
{
	if (data->fract == 0)
		mandelbrot_init(data);
	else if (data->fract == 1)
		julia_init(data);
	else if (data->fract == 3)
		mandelbar_init(data);
	else if (data->fract == 4)
		burning_ship_init(data);
	do_fract(data);
}

void	do_fract(t_e *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		make_mandelbrot_pthread(data);
	if (data->fract == 1)
		make_julia_pthread(data);
	if (data->fract == 3)
		make_mandelbar_pthread(data);
	if (data->fract == 4)
		make_burning_ship_pthread(data);
	if (data->show_text)
		put_text(data);
}

void	mlx_win_init(t_e *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fract'ol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img, &data->bpp,
	&data->sl, &data->endian);
}

void	get_first_data(char *str, t_e *data)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(str, "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(str, "mandelbar") == 0)
		data->fract = 3;
	else if (ft_strcmp(str, "burning_ship") == 0)
		data->fract = 4;
	else
	{
		free(data);
		ft_putstr("Try to use 'mandelbrot', 'mandelbar', 'burning_ship',");
		ft_putstr(" or 'julia'\n");
		exit(0);
	}
}
