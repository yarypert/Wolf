/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:45:41 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 17:58:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_image(t_ptr ptr)
{
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SIZE_X, SIZE_Y, "Wolf3D Yarypert");
	create_images(&ptr);
	set_adress(&ptr);
	mlx_hook(ptr.win, 17, (1L << 17), exit_cross, &ptr);
	mlx_hook(ptr.win, 2, (1L << 0), key_hook, &ptr);
	mlx_hook(ptr.win, 4, 0, mouse, &ptr);
	mlx_hook(ptr.win, 5, 0, mouse2, &ptr);
	mlx_loop_hook(ptr.mlx, burst, &ptr);
	init_wolf(&ptr);
	put_images(&ptr);
	put_guns(&ptr);
	weapons_info(&ptr);
	mlx_loop(ptr.mlx);
}

void	line(t_ptr *ptr, int color)
{
	t_init i;

	line_init(&i, *ptr);
	while (1)
	{
		mlx_pix_img(ptr, ptr->x1, ptr->y1, color);
		if (ptr->x1 == ptr->x2 && ptr->y1 == ptr->y2)
			return ;
		i.e2 = i.err;
		if (i.e2 > -i.dx)
		{
			i.err -= i.dy;
			ptr->x1 += i.sx;
		}
		if (i.e2 < i.dy)
		{
			i.err += i.dx;
			ptr->y1 += i.sy;
		}
	}
}

void	mlx_pix_img(t_ptr *ptr, int x, int y, int color)
{
	int r;
	int g;
	int b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	if (y >= 0 && x >= 0 && y < SIZE_Y && x < SIZE_X)
	{
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x) + 2] = r;
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x) + 1] = g;
		ptr->bts[(y * ptr->size_line) + ((ptr->bpp / 8) * x)] = b;
	}
}

void	line_init(t_init *i, t_ptr ptr)
{
	i->dx = abs(ptr.x2 - ptr.x1);
	i->sx = ptr.x1 < ptr.x2 ? 1 : -1;
	i->dy = abs(ptr.y2 - ptr.y1);
	i->sy = ptr.y1 < ptr.y2 ? 1 : -1;
	i->err = (i->dx > i->dy ? i->dx : -i->dy) / 2;
}
