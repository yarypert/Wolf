/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:23:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/23 19:31:30 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode, t_ptr *ptr)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 48)
		ptr->flag_map ^= 1;
	refresh(ptr);
	if (keycode == 15)
	{
		if(ptr->weapon_id == 0)
		{
			system("afplay Resources/SFX/AK47_Reload_SFX.mp3 &");
			usleep(3000000);
			ptr->ak_mag = 30;
		}
		else if (ptr->weapon_id == 1)
		{
			system("afplay Resources/SFX/DesertEagle_Reload_SFX.mp3");
			usleep(1500000);
			ptr->de_mag = 9;
		}
	}
	if (keycode == 11)
		ptr->ak_mode ^= 1;
	if (keycode == 126 || keycode == 125)
		ptr->weapon_id ^= 1;
	refresh(ptr);
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
			system("afplay Resources/SFX/AK47_Shot_SFX.mp3 &");
			ptr->ak_mag--;
			usleep(100000);
		}
		else if (keycode == 1 && ptr->ak_mag == 0)
		{
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
			usleep(100000);
		}
		else if (keycode == 1 && ptr->de_mag == 0)
		{
			system("afplay Resources/SFX/DesertEagle_Empty_SFX.mp3 &");
			usleep(100000);
		}
	}

	refresh(ptr);
	return(0);
}

int		refresh(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img);
	ptr->img = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->bts = mlx_get_data_addr(ptr->img, &(ptr->bpp), &(ptr->size_line), &(ptr->endian));
	//ft_bzero(ptr->bts, (SIZE_X * SIZE_Y) * ptr->bpp);
	if (ptr->flag_map)
		draw_map(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	weapons_info(ptr);
	return(0);
}
