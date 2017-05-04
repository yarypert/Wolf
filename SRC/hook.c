/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:23:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 20:05:02 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
	{
		destroy_images(ptr);
		free(ptr->map);
		exit(0);
	}
	if (keycode == 11)
		ptr->ak_mode ^= 1;
	if (keycode == 126 || keycode == 125)
		ptr->weapon_id ^= 1;
	reload(keycode, ptr);
	move(keycode, ptr);
	move2(keycode, ptr);
	refresh(ptr);
	return (0);
}

int		reload(int keycode, t_ptr *ptr)
{
	if (keycode == 15)
	{
		if (ptr->weapon_id == 0)
		{
			system("afplay Resources/SFX/AK47_Reload_SFX.mp3 &");
			usleep(3000000);
			ptr->ak_mag = ptr->ak_max;
		}
		else if (ptr->weapon_id == 1)
		{
			system("afplay Resources/SFX/DesertEagle_Reload_SFX.mp3 &");
			usleep(3000000);
			ptr->de_mag = 9;
		}
	}
	return (0);
}

int		move(int keycode, t_ptr *ptr)
{
	ptr->cst = 0.1;
	ptr->cst2 = 0.4;
	if (keycode == 13)
	{
		if (ptr->map[(int)(ptr->ray.posx +
					ptr->ray.dirx * ptr->cst2)][(int)(ptr->ray.posy)] == 0)
			ptr->ray.posx += ptr->ray.dirx * ptr->cst2;
		if (ptr->map[(int)(ptr->ray.posx)][(int)(ptr->ray.posy +
					ptr->ray.diry * ptr->cst2)] == 0)
			ptr->ray.posy += ptr->ray.diry * ptr->cst2;
	}
	if (keycode == 0)
	{
		ptr->ray.olddirx = ptr->ray.dirx;
		ptr->ray.dirx = ptr->ray.dirx * cos(ptr->cst) - ptr->ray.diry *
			sin(ptr->cst);
		ptr->ray.diry = ptr->ray.olddirx * sin(ptr->cst) + ptr->ray.diry *
			cos(ptr->cst);
		ptr->ray.oldplanex = ptr->ray.planex;
		ptr->ray.planex = ptr->ray.planex *
			cos(ptr->cst) - ptr->ray.planey * sin(ptr->cst);
		ptr->ray.planey = ptr->ray.oldplanex *
			sin(ptr->cst) + ptr->ray.planey * cos(ptr->cst);
	}
	return (0);
}

int		move2(int keycode, t_ptr *ptr)
{
	if (keycode == 1)
	{
		if (ptr->map[(int)(ptr->ray.posx - ptr->ray.dirx *
					ptr->cst2)][(int)(ptr->ray.posy)] == 0)
			ptr->ray.posx -= ptr->ray.dirx * ptr->cst2;
		if (ptr->map[(int)(ptr->ray.posx)][(int)(ptr->ray.posy -
					ptr->ray.diry * ptr->cst2)] == 0)
			ptr->ray.posy -= ptr->ray.diry * ptr->cst2;
	}
	if (keycode == 2)
	{
		ptr->ray.olddirx = ptr->ray.dirx;
		ptr->ray.dirx = ptr->ray.dirx * cos(-ptr->cst) -
			ptr->ray.diry * sin(-ptr->cst);
		ptr->ray.diry = ptr->ray.olddirx * sin(-ptr->cst) +
			ptr->ray.diry * cos(-ptr->cst);
		ptr->ray.oldplanex = ptr->ray.planex;
		ptr->ray.planex = ptr->ray.planex * cos(-ptr->cst) -
			ptr->ray.planey * sin(-ptr->cst);
		ptr->ray.planey = ptr->ray.oldplanex * sin(-ptr->cst) +
			ptr->ray.planey * cos(-ptr->cst);
	}
	return (0);
}

int		exit_cross(void)
{
	exit(0);
	return (0);
}
