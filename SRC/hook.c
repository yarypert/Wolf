/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:23:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/21 18:45:01 by yarypert         ###   ########.fr       */
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
	return (0);
}

int		exit_cross(void)
{
	exit(0);
	return (0);
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
return(0);
}
