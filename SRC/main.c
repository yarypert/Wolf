/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:47:06 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/25 16:51:13 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_ptr ptr;

	ptr.str = argv[1];
	if (argc == 3)
	{
		if (ft_strcmp(argv[1], "--map") == 0)
			ft_map();
		else if (ft_strcmp((argv[1]), "--format") == 0)
			ft_format();
		else if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 5], ".wolf") == 0)
		{
			ptr.name = argv[2];
			ptr.read = read_file(argv[1]);
			ptr_init(&ptr);
			parse(&ptr);
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
	ptr->ak_mag = 30;
	ptr->de_mag = 9;
	ptr->i = 0;
	ptr->j = 0;
	ptr->k = 0;
	ptr->flag_map = 0;
}

void	sprt_size_init(t_ptr *ptr)
{
	ptr->sprt.ak01w = 634;
	ptr->sprt.ak01h = 606;
}
