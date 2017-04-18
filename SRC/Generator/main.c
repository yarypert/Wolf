/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 00:51:56 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/18 08:08:23 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapGen.h"

int		main(int argc, char **argv)
{
	t_gen			gen;
	unsigned int	seed;

	read(open("/dev/urandom", O_RDONLY), &seed, sizeof(seed));
	srand(seed);
	if (argc == 4)
	{
		gen.line = ft_atoi(argv[1]);
		gen.column = ft_atoi(argv[2]);
		gen.percent = ft_atoi(argv[3]);
		if (gen.percent < 0 || gen.percent > 42 || gen.column > 50 ||
gen.line > 50 || gen.line <= 4 || gen.column <= 4)
			ft_usage();
		create_map(&gen);
		ft_putendl("\033[38;5;28m===Generator : Map Created.\033[0m");
	}
	else
		ft_usage();
	return (0);
}
