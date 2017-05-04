/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 07:19:01 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 17:42:12 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_wolf(t_ptr *ptr)
{
	ptr->ray.i = 0;
	while (ptr->ray.i < SIZE_X)
	{
		ptr->ray.camerax = 2 * ptr->ray.i / (double)(SIZE_X) - 1;
		ptr->ray.rayposx = ptr->ray.posx;
		ptr->ray.rayposy = ptr->ray.posy;
		ptr->ray.raydirx = ptr->ray.dirx + ptr->ray.planex * ptr->ray.camerax;
		ptr->ray.raydiry = ptr->ray.diry + ptr->ray.planey * ptr->ray.camerax;
		init_wolf2(ptr);
		init_wolf3(ptr);
		init_wolf4(ptr);
		init_wolf5(ptr);
		ptr->ray.i++;
	}
}

void	init_wolf2(t_ptr *ptr)
{
	ptr->ray.mapx = (int)ptr->ray.rayposx;
	ptr->ray.mapy = (int)ptr->ray.rayposy;
	ptr->ray.deltadistx = sqrt(1 + (ptr->ray.raydiry * ptr->ray.raydiry) / (ptr->ray.raydirx * ptr->ray.raydirx));
	ptr->ray.deltadisty = sqrt(1 + (ptr->ray.raydirx * ptr->ray.raydirx) / (ptr->ray.raydiry * ptr->ray.raydiry));
	ptr->ray.hit = 0;
	if (ptr->ray.raydirx < 0)
	{
		ptr->ray.stepx = -1;
		ptr->ray.sidedistx = (ptr->ray.rayposx - ptr->ray.mapx) * ptr->ray.deltadistx;
	}
	else
	{
		ptr->ray.stepx = 1;
		ptr->ray.sidedistx = (ptr->ray.mapx + 1.0 - ptr->ray.rayposx) * ptr->ray.deltadistx;
	}
	if (ptr->ray.raydiry < 0)
	{
		ptr->ray.stepy = -1;
		ptr->ray.sidedisty = (ptr->ray.rayposy - ptr->ray.mapy) * ptr->ray.deltadisty;
	}
	else
	{
		ptr->ray.stepy = 1;
		ptr->ray.sidedisty = (ptr->ray.mapy + 1.0 - ptr->ray.rayposy) * ptr->ray.deltadisty;
	}
}

void	init_wolf3(t_ptr *ptr)
{
	while (ptr->ray.hit == 0)
	{
		if (ptr->ray.sidedistx < ptr->ray.sidedisty)
		{
			ptr->ray.sidedistx += ptr->ray.deltadistx;
			ptr->ray.mapx += ptr->ray.stepx;
			ptr->ray.side = 0;
		}
		else
		{
			ptr->ray.sidedisty += ptr->ray.deltadisty;
			ptr->ray.mapy += ptr->ray.stepy;
			ptr->ray.side = 1;
		}
		if (ptr->map[ptr->ray.mapx][ptr->ray.mapy] > 0)
			ptr->ray.hit = 1;
	}
}

void	init_wolf4(t_ptr *ptr)
{
	if (ptr->ray.side == 0)
		ptr->ray.perpwalldist = (ptr->ray.mapx - ptr->ray.rayposx + (1 - ptr->ray.stepx) / 2) / ptr->ray.raydirx;
	else
		ptr->ray.perpwalldist = (ptr->ray.mapy - ptr->ray.rayposy + (1 - ptr->ray.stepy) / 2) / ptr->ray.raydiry;
	ptr->ray.lineheight = (int)(SIZE_Y / ptr->ray.perpwalldist);
	ptr->ray.drawstart = -ptr->ray.lineheight / 2 + SIZE_Y / 2;
	if (ptr->ray.drawstart < 0)
		ptr->ray.drawstart = 0;
	ptr->ray.drawend = ptr->ray.lineheight / 2 + SIZE_Y / 2;
	if (ptr->ray.drawend >= SIZE_Y)
		ptr->ray.drawend = SIZE_Y - 1;
}

void		init_wolf5(t_ptr *ptr)
{
	ptr->ray.color = 0x00FF00FF;
	if (ptr->ray.side == 0)
		ptr->ray.color = (ptr->ray.stepx == -1 ? RED : YELLOW);
	else
		ptr->ray.color = (ptr->ray.stepy == -1 ? BLUE : GREEN);
	if (ptr->ray.side == 1)
		ptr->ray.color = ptr->ray.color / 2;
	ptr->x1 = ptr->ray.i;
	ptr->y1 = ptr->ray.drawstart;
	ptr->x2 = ptr->ray.i;
	ptr->y2 = ptr->ray.drawend;
	line (ptr, ptr->ray.color);
	ptr->x1 = ptr->ray.i;
	ptr->y1 = ptr->ray.drawstart;
	ptr->x2 = ptr->ray.i;
	ptr->y2 = 0;
	line (ptr, 0x00444444);
	ptr->x1 = ptr->ray.i;
	ptr->y1 = SIZE_Y;
	ptr->x2 = ptr->ray.i;
	ptr->y2 = ptr->ray.drawend;
	line (ptr, 0x00999999);
}
