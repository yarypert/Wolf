/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:55:03 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/18 08:54:27 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	line_len(t_ptr *ptr)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	ptr->line = 0;
	while (ptr->read[i] != '\0')
	{
		ptr->column = 0;
		while (ptr->read[i] != '\n' && ptr->read[i])
		{
			if ((ptr->read[i] == 'X' || ptr->read[i] == '.' ||
						ptr->read[i] == '1' || ptr->read[i] == '0') &&
					(ptr->read[i + 1] == ' ' || ptr->read[i + 1] == '\n'))
				ptr->column++;
			i++;
		}
		if (flag == 0)
			flag = ptr->column;
		if (ptr->column != flag)
			ft_error("file not valid. (\"./Wolf3D --format\" for help)");
		ptr->line++;
		i++;
	}
}

void	count_zero(t_ptr *ptr)
{
	int player;
	int i;

	i = 0;
	player = 0;
	while (ptr->read[i])
	{
		if (ptr->read[i] == '0')
			player++;
		i++;
	}
	if (player != 1)
	{
		ft_putstr("Player count = ");
		ft_putnbr(player);
		ft_error(" , please set it to 1");
	}
}

void	fill_tab(t_ptr *ptr)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < ptr->line)
	{
		j = 0;
		fill_tab2(ptr, i, j, k);
		i++;
	}
}

void	fill_tab2(t_ptr *ptr, int i, int j, int k)
{
	while (j < ptr->column)
	{
		if (ptr->read[k] == ' ' || ptr->read[k] == '\n')
			k++;
		if (ptr->read[k] == 'X' || ptr->read[k] == '1')
		{
			ptr->map[i][j] = 1;
			k += 2;
			j++;
		}
		if (ptr->read[k] == '.')
		{
			ptr->map[i][j] = 0;
			k += 2;
			j++;
		}
		if (ptr->read[k] == '0')
		{
			ptr->map[i][j] = 0;
			ptr->player_i = i;
			ptr->player_j = j;
			k += 2;
			j++;
		}
	}
}

void	first_check(t_ptr *ptr)
{
	int i;

	i = 0;
	while (ptr->read[i])
	{
		if (ptr->read[i] != 'X' && ptr->read[i] != '.' &&
				ptr->read[i] != '1' && ptr->read[i] != '0' &&
				ptr->read[i] != 'X')
			ft_usage();
		i++;
	}
}
