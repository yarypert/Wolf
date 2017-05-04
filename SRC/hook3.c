/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:11:20 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 19:13:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mouse3(int keycode, t_ptr *ptr)
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
		mouse3(keycode, ptr);
	}
	return (0);
}
