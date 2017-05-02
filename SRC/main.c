/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:47:06 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/02 17:16:24 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_ptr ptr;
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "--map") == 0)
			ft_map();
		else if (ft_strcmp((argv[1]), "--format") == 0)
			ft_format();
	}
	ptr.str = argv[1];
	if (argc == 3)
	{
		if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 5], ".wolf") == 0)
		{
			if (ft_strlen(argv[2]) > 7)
				ft_usage();
			ptr.name = argv[2];
			ptr.read = read_file(argv[1]);
			ptr_init(&ptr);
			parse(&ptr);
			ray_init(&ptr);
			draw_image(ptr);
		}
		else
			ft_usage();
	}
	else
		ft_usage();
}

void	ptr_init(t_ptr *ptr)
{
	ptr->sprt.sizex = SIZE_X;
	ptr->sprt.sizey = SIZE_Y;
	ptr->weapon_id = 0;
	ptr->ak_max = 30;
	ptr->ak_mag = ptr->ak_max;
	ptr->de_mag = 9;
	ptr->i = 0;
	ptr->j = 0;
	ptr->k = 0;
	ptr->flag_map = 0;
	ptr->shot = 0;
}

void	ray_init(t_ptr *ptr)
{
	ptr->ray.i = 0;
	ptr->ray.posX = ptr->player_i;
	ptr->ray.posY = ptr->player_j;
	ptr->ray.dirX = -1;
	ptr->ray.dirY = 0;
	ptr->ray.planeX = 0;
	ptr->ray.planeY = 0.66;
	ptr->ray.cameraX = 2 * ptr->ray.i / (double)(SIZE_X) - 1;
	ptr->ray.rayposX = ptr->ray.posX;
	ptr->ray.rayposY = ptr->ray.posY;
	ptr->ray.raydirX = ptr->ray.dirX + ptr->ray.planeX * ptr->ray.cameraX;
	ptr->ray.raydirY = ptr->ray.dirY + ptr->ray.planeY * ptr->ray.cameraX;
}
