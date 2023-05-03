/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:09:15 by acaldas           #+#    #+#             */
/*   Updated: 2023/04/27 22:10:04 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot_init(t_fractol *f)
{
	f->min_re = -2.2;
	f->max_re = 1.0;
	f->min_im = -1.5;
	f->max_im = (f->max_re - f->min_re) + f->min_im;
	f->it_max = 100;
	f->color = 265;
}

void	mandelbrot(t_fractol *f)
{
	double		x;
	double		y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			mandelbrot_math(f, y, x);
			y++;
		}
		x++;
	}
}

void	mandelbrot_math(t_fractol *f, double x, double y)
{
	int	inter;

	f->c_r = f-> min_re + (x * (f->max_re - f->min_re)) / WIDTH;
	f->c_i = f-> min_im + (y * (f->max_im - f->min_im)) / HEIGTH;
	f->z_r = 0;
	f->z_i = 0;
	inter = 0;
	f->tmp = 0;
	while (inter < f->it_max)
	{
		f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
		f->z_i = 2 * f->z_i * f->z_r + f->c_i;
		f->z_r = f->tmp;
		if (f->z_r * f->z_r + f->z_i * f->z_i > 4)
			break ;
		inter++;
	}
	if (inter == f->it_max)
		put_pxl_to_img(f, x, y, 0xfcbdb);
	else
		put_pxl_to_img(f, x, y, (inter * f->color * inter));
}
