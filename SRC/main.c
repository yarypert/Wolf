/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:47:06 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/21 18:01:18 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int argc, char **argv)
{
	t_ptr ptr;

	ptr.i = 0;
	ptr.j = 0;
	ptr.k = 0;
	ptr.flag_map = 0;
	ptr.str = argv[1];
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "--map") == 0)
			ft_map();
		else if (ft_strcmp((argv[1]), "--format") == 0)
			ft_format();
		else if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 5], ".wolf") == 0)
		{
			ptr.read = read_file(argv[1]);
			parse(&ptr);
			draw_image(ptr);
		}
		else
			ft_usage();
	}
	else
		ft_usage();
}
