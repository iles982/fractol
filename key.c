/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 03:05:29 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/16 10:12:53 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook2(int keycode, t_e *data)
{
	if (keycode == 18)
		data->color = 1677216;
	else if (keycode == 19)
		data->color = 2050;
	else if (keycode == 20)
		data->color = 265;
	else if (keycode == 13)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 1)
		data->show_text = !data->show_text;
	return (0);
}

int		key_hook(int keycode, t_e *data)
{
	if (keycode == 53)
	{
		free(data);
		exit(1);
	}
	else if (keycode == 69)
		data->it_max += 50;
	else if (keycode == 78)
	{
		if (data->it_max > 50)
			data->it_max -= 50;
	}
	else if (keycode == 123)
		data->x1 -= 30 / data->zoom;
	else if (keycode == 124)
		data->x1 += 30 / data->zoom;
	else if (keycode == 125)
		data->y1 += 30 / data->zoom;
	else if (keycode == 126)
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49)
		fract_init(data);
	key_hook2(keycode, data);
	do_fract(data);
	return (0);
}

void	ft_zoom(int x, int y, t_e *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_e *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_e *data)
{
	if (y > 0 && y < WIDTH && x > 0 && x < WIDTH)
	{
		if (mousecode == 4 || mousecode == 1)
			ft_zoom(x, y, data);
		else if (mousecode == 5 || mousecode == 2)
			ft_dezoom(x, y, data);
	}
	do_fract(data);
	return (0);
}
