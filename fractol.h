/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 02:01:16 by tclarita          #+#    #+#             */
/*   Updated: 2019/11/16 10:14:25 by tclarita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# define WIDTH 600
# define THREAD_WIDTH 5
# define THREAD_NUMBER 120

# define MAX1(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct		s_e
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_ptr;
	int				endian;
	int				sl;
	int				bpp;
	int				fract;
	int				color;
	int				julia_mouse;
	int				x;
	int				y;
	int				y_max;
	int				it;
	int				it_max;
	int				show_text;
	double			zoom;
	double			x1;
	double			y1;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
}					t_e;

void				burning_ship_init(t_e *data);
void				do_burning_ship(t_e *data);
void				*burning_ship(void *tab);
void				make_burning_ship_pthread(t_e *data);

void				mandelbar_init(t_e *data);
void				make_mandelbar_pthread(t_e *data);

void				put_text(t_e *data);
int					exit_cl(void);
void				put_pxl_to_img(t_e *data, int x, int y, int color);
int					key_hook2(int keycode, t_e *data);
int					key_hook(int keycode, t_e *data);
void				ft_zoom(int x, int y, t_e *data);
void				ft_dezoom(int x, int y, t_e *data);
int					mouse_hook(int mousecode, int x, int y, t_e*data);

void				julia_init(t_e *data);
void				julia_calc(t_e *data);
void				*julia(void *tab);
void				make_julia_pthread(t_e *data);
int					mouse_julia(int x, int y, t_e *data);

void				make_mandelbrot_pthread(t_e *data);
void				*mandelbrot(void *tab);
void				do_mandelbrot(t_e *data);
void				mandelbrot_init(t_e *data);

void				get_first_data(char *str, t_e *data);
void				mlx_win_init(t_e *data);
void				do_fract(t_e *data);
void				fract_init(t_e *data);

#endif
