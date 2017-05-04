/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:09:24 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 19:10:10 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		tricks(int i)
{
	static int	onfire;

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
