/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:25:19 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/28 03:18:17 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_images(t_ptr *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.menu, 0, 0);
}

void	put_guns(t_ptr *ptr)
{
	if (ptr->weapon_id == 0)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.akwep, 0, 0);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.ak01, 0, 0);
	}
	else if (ptr->weapon_id == 1)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.dewep, 0, 0);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.de01, 0, 0);
	}
}

void	put_guns_fire(t_ptr *ptr)
{
	if (ptr->weapon_id == 0)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.akwep, 0, 0);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.ak02, 0, 0);
	}
	else if (ptr->weapon_id == 1)
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.dewep, 0, 0);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.de02, 0, 0);
	}
}
