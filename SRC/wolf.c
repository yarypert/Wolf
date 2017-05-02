/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 07:19:01 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/02 16:23:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_wolf(t_ptr *ptr)
{
	ptr->ray.i = 0;
	ptr->ray.posX = ptr->player_i;
	ptr->ray.posY = ptr->player_j;
	ptr->ray.dirX = -1;
	ptr->ray.dirY = 0;
	ptr->ray.planeX = 0;
	ptr->ray.planeY = 0.66;

	while (ptr->ray.i < SIZE_X)
	{
		ptr->ray.cameraX = 2 * ptr->ray.i / (double)(SIZE_X) - 1;
		ptr->ray.rayposX = ptr->ray.posX;
		ptr->ray.rayposY = ptr->ray.posY;
		ptr->ray.raydirX = ptr->ray.dirX + ptr->ray.planeX * ptr->ray.cameraX;
		ptr->ray.raydirY = ptr->ray.dirY + ptr->ray.planeY * ptr->ray.cameraX;
		init_wolf2(ptr);
		init_wolf3(ptr);
		init_wolf4(ptr);
		init_wolf5(ptr);
		ptr->ray.i++;
	}
}

void	init_wolf2(t_ptr *ptr)
{
	ptr->ray.mapX = (int)ptr->ray.rayposX;
	ptr->ray.mapY = (int)ptr->ray.rayposY;
	ptr->ray.deltadistX = sqrt(1 + (ptr->ray.raydirY * ptr->ray.raydirY) / (ptr->ray.raydirX * ptr->ray.raydirX));
	ptr->ray.deltadistY = sqrt(1 + (ptr->ray.raydirX * ptr->ray.raydirX) / (ptr->ray.raydirY * ptr->ray.raydirY));
	ptr->ray.hit = 0;
	if (ptr->ray.raydirX < 0)
	{
		ptr->ray.stepX = -1;
		ptr->ray.sidedistX = (ptr->ray.rayposX - ptr->ray.mapX) * ptr->ray.deltadistX;
	}
	else
	{
		ptr->ray.stepX = 1;
		ptr->ray.sidedistX = (ptr->ray.mapX + 1.0 - ptr->ray.rayposX) * ptr->ray.deltadistX;
	}
	if (ptr->ray.raydirY < 0)
	{
		ptr->ray.stepY = -1;
		ptr->ray.sidedistY = (ptr->ray.rayposY - ptr->ray.mapY) * ptr->ray.deltadistY;
	}
	else
	{
		ptr->ray.stepY = 1;
		ptr->ray.sidedistY = (ptr->ray.mapY + 1.0 - ptr->ray.rayposY) * ptr->ray.deltadistY;
	}
}

void	init_wolf3(t_ptr *ptr)
{
	while (ptr->ray.hit == 0)
	{
		if (ptr->ray.sidedistX < ptr->ray.sidedistY)
		{
			ptr->ray.sidedistX += ptr->ray.deltadistX;
			ptr->ray.mapX += ptr->ray.stepX;
			ptr->ray.side = 0;
		}
		else
		{
			ptr->ray.sidedistY += ptr->ray.deltadistY;
			ptr->ray.mapY += ptr->ray.stepY;
			ptr->ray.side = 1;
		}
		if (ptr->map[ptr->ray.mapX][ptr->ray.mapY] > 0)
			ptr->ray.hit = 1;
	}
}

void	init_wolf4(t_ptr *ptr)
{
	if (ptr->ray.side == 0)
		ptr->ray.perpwalldist = (ptr->ray.mapX - ptr->ray.rayposX + (1 - ptr->ray.stepX) / 2) / ptr->ray.raydirX;
	else
		ptr->ray.perpwalldist = (ptr->ray.mapY - ptr->ray.rayposY + (1 - ptr->ray.stepY) / 2) / ptr->ray.raydirY;
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
		ptr->ray.color = (ptr->ray.stepX == -1 ? RED : YELLOW);
	else
		ptr->ray.color = (ptr->ray.stepY == -1 ? BLUE : GREEN);
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
