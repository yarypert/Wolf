/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:47:06 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 17:58:05 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_ptr ptr;

	if (argc == 2)
		main_to_usage(argv);
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

void	main_to_usage(char **argv)
{
	if (ft_strcmp(argv[1], "--map") == 0)
		ft_map();
	else if (ft_strcmp((argv[1]), "--format") == 0)
		ft_format();
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
	ptr->ray.posx = ptr->player_i;
	ptr->ray.posy = ptr->player_j;
	ptr->ray.dirx = -1;
	ptr->ray.diry = 0;
	ptr->ray.planex = 0;
	ptr->ray.planey = 0.66;
	ptr->ray.camerax = 2 * ptr->ray.i / (double)(SIZE_X) - 1;
	ptr->ray.rayposx = ptr->ray.posx;
	ptr->ray.rayposy = ptr->ray.posy;
	ptr->ray.raydirx = ptr->ray.dirx + ptr->ray.planex * ptr->ray.camerax;
	ptr->ray.raydiry = ptr->ray.diry + ptr->ray.planey * ptr->ray.camerax;
}
