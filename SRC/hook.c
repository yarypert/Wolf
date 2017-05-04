/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:23:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 17:47:03 by yarypert         ###   ########.fr       */
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

int move2(int keycode, t_ptr *ptr)
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

int		mouse(int keycode, int x, int y, t_ptr *ptr)
{
	if (ptr->weapon_id == 0)
	{
		if (keycode == 1 && ptr->ak_mag != 0)
		{
			tricks(1);
			system("afplay Resources/SFX/AK47_Shot_SFX.mp3 &");
			ptr->ak_mag--;
			refreshfire(ptr);
			mlx_do_sync(ptr->mlx);
			refresh(ptr);
		}
		else if (keycode == 1 && ptr->ak_mag == 0)
		{
			tricks(0);
			system("afplay Resources/SFX/AK47_Empty_SFX.mp3 &");
			usleep(100000);
		}
	}
	else if (ptr->weapon_id == 1)
	{
		if (keycode == 1 && ptr->de_mag != 0)
		{
			system("afplay Resources/SFX/DesertEagle_Shot_SFX.mp3 &");
			ptr->de_mag--;
			refreshfire(ptr);
			mlx_do_sync(ptr->mlx);
			usleep(100000);
			refresh(ptr);
		}
		else if (keycode == 1 && ptr->de_mag == 0)
		{
			system("afplay Resources/SFX/DesertEagle_Empty_SFX.mp3 &");
			usleep(100000);
		}
	}
	return (0);
}

int		tricks(int i)
{
	static int		onfire;

	if (i == 1 && onfire != 1)
		onfire = 1;
	else if (i == 0 && onfire != 0)
		onfire = 0;
	return (onfire);
}

int		burst(t_ptr *ptr)
{
	if (tricks(-1) && ptr->ak_mag > 0)
	{
		system("afplay Resources/SFX/AK47_Shot_SFX.mp3 &");
		ptr->ak_mag--;
		refreshfire(ptr);
		mlx_do_sync(ptr->mlx);
		refresh(ptr);
		mlx_do_sync(ptr->mlx);
	}
	return (0);
}

int		mouse2(int keycode, int x, int y, t_ptr *ptr)
{
	tricks(0);
	return (0);
}

int		refresh(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	destroy_images(ptr);
	create_images(ptr);
	set_adress(ptr);
	init_wolf(ptr);
	put_images(ptr);
	put_guns(ptr);
	weapons_info(ptr);
	return (0);
}

int		refreshfire(t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	destroy_images(ptr);
	create_images(ptr);
	set_adress(ptr);
	init_wolf(ptr);
	put_images(ptr);
	put_guns_fire(ptr);
	weapons_info(ptr);
	return (0);
}
