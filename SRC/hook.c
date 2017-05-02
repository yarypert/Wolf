/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:23:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/02 17:13:27 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 15)
	{
		if(ptr->weapon_id == 0)
		{
			system("afplay Resources/SFX/AK47_Reload_SFX.mp3 &");
			usleep(3000000);
			ptr->ak_mag = ptr->ak_max;;
		}
		else if (ptr->weapon_id == 1)
		{
			system("afplay Resources/SFX/DesertEagle_Reload_SFX.mp3 &");
			usleep(3000000);
			ptr->de_mag = 9;
		}
	}
	if (keycode == 11)
		ptr->ak_mode ^= 1;
	if (keycode == 126 || keycode == 125)
		ptr->weapon_id ^= 1;
	move(keycode, ptr);
	refresh(ptr);
	return (0);
}

int		move(int keycode, t_ptr *ptr)
{
	double cst = 0.1;
	double cst2 = 0.4;
	if (keycode == 13)
	{
		if(ptr->map[(int)(ptr->ray.posX + ptr->ray.dirX * cst2)][(int)(ptr->ray.posY)] == 0)
			ptr->ray.posX += ptr->ray.dirX * cst2;
		if(ptr->map[(int)(ptr->ray.posX)][(int)(ptr->ray.posY + ptr->ray.dirY * cst2)] == 0)
			ptr->ray.posY += ptr->ray.dirY * cst2;
	}
	if (keycode == 0)
	{
		ptr->ray.olddirX = ptr->ray.dirX;
		ptr->ray.dirX = ptr->ray.dirX * cos(cst) - ptr->ray.dirY * sin(cst);
		ptr->ray.dirY = ptr->ray.olddirX * sin(cst) + ptr->ray.dirY * cos(cst);
		ptr->ray.oldplaneX = ptr->ray.planeX;
		ptr->ray.planeX = ptr->ray.planeX * cos(cst) - ptr->ray.planeY * sin(cst);
		ptr->ray.planeY = ptr->ray.oldplaneX * sin(cst) + ptr->ray.planeY * cos(cst);
	}
	if (keycode == 1)
	{
		if(ptr->map[(int)(ptr->ray.posX - ptr->ray.dirX * cst2)][(int)(ptr->ray.posY)] == 0)
			ptr->ray.posX -= ptr->ray.dirX * cst2;
		if(ptr->map[(int)(ptr->ray.posX)][(int)(ptr->ray.posY - ptr->ray.dirY * cst2)] == 0)
			ptr->ray.posY -= ptr->ray.dirY * cst2;
	}
	if (keycode == 2)
	{
		ptr->ray.olddirX = ptr->ray.dirX;
		ptr->ray.dirX = ptr->ray.dirX * cos(-cst) - ptr->ray.dirY * sin(-cst);
		ptr->ray.dirY = ptr->ray.olddirX * sin(-cst) + ptr->ray.dirY * cos(-cst);
		ptr->ray.oldplaneX = ptr->ray.planeX;
		ptr->ray.planeX = ptr->ray.planeX * cos(-cst) - ptr->ray.planeY * sin(-cst);
		ptr->ray.planeY = ptr->ray.oldplaneX * sin(-cst) + ptr->ray.planeY * cos(-cst);
	}
return(0);
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
	else if(ptr->weapon_id == 1)
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
	return(0);
}

int		tricks(int i)
{
	static int		onfire;

	if (i == 1 && onfire != 1)
		onfire = 1;
	else if (i == 0 && onfire != 0)
		onfire = 0;
	return (onfire);
};

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
	return(0);
}

int		mouse2(int keycode, int x, int y, t_ptr *ptr)
{
	tricks(0);
	return(0);
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
	return(0);
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
	return(0);
}
