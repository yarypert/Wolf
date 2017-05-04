/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:25:19 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 16:45:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	destroy_images(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img);
	mlx_destroy_image(ptr->mlx, ptr->sprt.menu);
	mlx_destroy_image(ptr->mlx, ptr->sprt.akwep);
	mlx_destroy_image(ptr->mlx, ptr->sprt.dewep);
	mlx_destroy_image(ptr->mlx, ptr->sprt.de01);
	mlx_destroy_image(ptr->mlx, ptr->sprt.de02);
	mlx_destroy_image(ptr->mlx, ptr->sprt.ak01);
	mlx_destroy_image(ptr->mlx, ptr->sprt.ak02);
	mlx_destroy_image(ptr->mlx, ptr->sprt.akbul);
	mlx_destroy_image(ptr->mlx, ptr->sprt.debul);
}
