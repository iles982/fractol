/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 09:57:26 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/16 10:02:22 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burning_ship_init(t_e *data)
{
	data->it_max = 50;
	data->zoom = 300;
	data->x1 = -2.05;
	data->y1 = -1.3;
	data->color = 265;
}

void	do_burning_ship(t_e *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
	&& data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r - data->z_i * data->z_i + data->c_r;
		data->z_i = -2 * fabs(data->z_i * data->tmp) + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 1544243);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*burning_ship(void *tab)
{
	t_e *data;
	int	i;

	data = (t_e *)tab;
	data->x = 0;
	i = data->y;
	while (data->x < WIDTH)
	{
		data->y = i;
		while (data->y < data->y_max)
		{
			do_burning_ship(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	make_burning_ship_pthread(t_e *data)
{
	t_e			tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_e));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, burning_ship, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
