/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaldas <acaldas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:07:43 by acaldas           #+#    #+#             */
/*   Updated: 2023/04/27 22:21:06 by acaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color(t_fractol *f)
{
	static int	colors;

	colors++;
	if (colors == 6)
		colors = 0;
	if (colors == 0)
		f->color = 265;
	else if (colors == 1)
		f->color = 1677216;
	else if (colors == 2)
		f->color = 433216;
	else if (colors == 3)
		f->color = 2377216;
	else if (colors == 4)
		f->color = 677212;
	else if (colors == 5)
		f->color = 37212;
}

int	key_hook(int keycode, t_fractol *f)
{
	ft_printf("key: %d\n", keycode);
	if (keycode == 65307)
		close_win(f);
	else if (keycode == 'a')
		f->it_max += 50;
	else if (keycode == 'd')
		f->it_max -= 50;
	else if (keycode == 'r')
		fract_init(f);
	else if (keycode == 'c')
		color(f);
	draw_frac(f);
	return (0);
}
