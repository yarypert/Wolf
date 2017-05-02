/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:25:19 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/02 06:47:34 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_images(t_ptr *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.menu, 0, 0);
	ak_bullet(ptr);
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


void	ak_bullet(t_ptr *ptr)
{
	int i;

	i = 0;
	while(i < ptr->ak_mag)
	{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.akbul, 0 + (7 * i), 0);
	i++;
	}
	i = 0;
	while (i < ptr->de_mag)
	{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->sprt.debul, 0 + (22 * i), -5);
	i++;
	}
}
