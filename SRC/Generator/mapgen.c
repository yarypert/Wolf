/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 00:57:46 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/18 08:00:05 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapGen.h"

void	alloc_map(t_gen *gen)
{
	int i;

	i = 0;
	gen->map = ((char **)malloc(sizeof(char *) * (gen->line)));
	while (i < gen->line)
	{
		gen->map[i] = ((char *)malloc(sizeof(char) * (gen->column * 2 - 1)));
		i++;
	}
	gen->str_map = ((char *)malloc((sizeof(char) *
gen->column * 2) * gen->line));
}

void	print(t_gen *gen)
{
	int i;

	i = 0;
	while (i < gen->line)
	{
		ft_putendl(gen->map[i]);
		i++;
	}
}

void	tab_to_str(t_gen *gen)
{
	int i;

	i = 0;
	while (i < gen->line)
	{
		gen->str_map = ft_strjoin(gen->str_map, gen->map[i]);
		gen->str_map = ft_strjoin(gen->str_map, "\n");
		i++;
	}
}

void	put_to_file(t_gen *gen)
{
	int fd;

	fd = open("Map.wolf", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putstr_fd(gen->str_map, fd);
	if (fd == -1)
		ft_error("open() error");
	if (close(fd) == -1)
	{
		ft_error("close() error");
	}
}

void	create_map(t_gen *gen)
{
	int i;
	int val;

	i = 0;
	val = (gen->percent * ((gen->line - 2) * (gen->column - 2) - 1)) / 100;
	alloc_map(gen);
	fill_map_walls(gen);
	while (i < val)
	{
		place_player(gen, '1');
		i++;
	}
	last_check(gen, '1', '.', 'X');
	last_check(gen, '.', '1', 'X');
	place_player(gen, '0');
	tab_to_str(gen);
	put_to_file(gen);
}
