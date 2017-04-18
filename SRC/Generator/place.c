/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 01:11:40 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/18 01:14:22 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapGen.h"

void	cond_walls(t_gen *gen, int i, int j)
{
	if (gen->map[i][j] == '1')
	{
		if (i - 1 > 0 && gen->map[i - 1][j] == '.' && gen->rand == 0)
			gen->map[i][j] = '0';
		if (i + 1 < gen->line && gen->map[i + 1][j] == '.' && gen->rand == 1)
			gen->map[i][j] = '0';
		if (j - 2 > 0 && gen->map[i][j - 2] == '.' && gen->rand == 2)
			gen->map[i][j] = '0';
		if (j + 2 < gen->column && gen->map[i][j + 2] == '.' && gen->rand == 3)
			gen->map[i][j] = '0';
	}
}

void	place_wall(t_gen *gen)
{
	int i;
	int j;

	i = 0;
	gen->rand = rand() % 4;
	while (i < gen->line - 1)
	{
		j = 0;
		while (j < gen->column * 2 - 2)
		{
			cond_walls(gen, i, j);
			j++;
		}
		i++;
	}
}

void	last_check(t_gen *gen, char a, char b, char c)
{
	int i;
	int j;

	i = 1;
	gen->link = 0;
	while (i < gen->line - 1)
	{
		j = 1;
		while (j < gen->column * 2 - 2)
		{
			if (gen->map[i][j] == a)
			{
				if ((gen->map[i - 1][j] == b || gen->map[i - 1][j] == c)
						&& (gen->map[i + 1][j] == b || gen->map[i + 1][j] == c)
						&& (gen->map[i][j - 2] == b || gen->map[i][j - 2] == c)
						&& (gen->map[i][j + 2] == b || gen->map[i][j + 2] == c))
					gen->map[i][j] = b;
			}
			j++;
		}
		i++;
	}
}

void	place_player(t_gen *gen, char c)
{
	int i;
	int j;

	i = 1;
	while (i < gen->line - 1)
	{
		j = 2;
		while (j < gen->column * 2 - 2)
		{
			gen->rand = rand() % 1000;
			if (gen->rand < 1 && gen->map[i][j] == '.' && gen->map[i][j] != '0')
			{
				gen->map[i][j] = c;
				return ;
			}
			j += 2;
		}
		i++;
	}
	place_player(gen, c);
}

void	fill_map_walls(t_gen *gen)
{
	int i;
	int j;

	i = 0;
	while (i < gen->line)
	{
		j = 0;
		while (j < gen->column * 2)
		{
			if (i == 0 || i == gen->line - 1 || j == 0 || j ==
gen->column * 2 - 2)
				gen->map[i][j] = 'X';
			else
				gen->map[i][j] = '.';
			gen->map[i][j + 1] = ' ';
			j += 2;
		}
		gen->map[i][gen->column * 2 - 1] = '\0';
		i++;
	}
}
