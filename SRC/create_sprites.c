/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:25:19 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/01 21:40:40 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	create_images(t_ptr *ptr)
{
	ptr->img = mlx_new_image(ptr->mlx, SIZE_X, SIZE_Y);
	ptr->sprt.menu = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/menu.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);

	ptr->sprt.dewep = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/dewep.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);
	ptr->sprt.de01 = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/de01.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);
	ptr->sprt.de02 = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/de02.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);
	ptr->sprt.akwep = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/akwep.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);
	ptr->sprt.ak01 = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/ak01.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);
	ptr->sprt.ak02 = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/ak02.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);


	ptr->sprt.akbul = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/AK47_Bullet.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);
	ptr->sprt.debul = mlx_xpm_file_to_image(ptr->mlx, "./Resources/Sprites/XPM/DE_Bullet.xpm", &ptr->sprt.sizex, &ptr->sprt.sizey);


}

