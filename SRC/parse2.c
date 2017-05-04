/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:55:03 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 18:21:53 by yarypert         ###   ########.fr       */
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
	line_dif_col(ptr);
}

void	line_dif_col(t_ptr *ptr)
{
	if (ptr->line != ptr->column)
		ft_error("file not valid. (\"./Wolf3D --format\" for help)");
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
	while (ptr->i < ptr->line)
	{
		ptr->j = 0;
		while (ptr->j < ptr->column)
			fill_tab2(ptr);
		ptr->i++;
	}
}

void	fill_tab2(t_ptr *ptr)
{
	if (ptr->read[ptr->k] == ' ' || ptr->read[ptr->k] == '\n')
		ptr->k++;
	if (ptr->read[ptr->k] == 'X' || ptr->read[ptr->k] == '1')
	{
		ptr->map[ptr->i][ptr->j] = 1;
		ptr->k += 2;
		ptr->j++;
	}
	if (ptr->read[ptr->k] == '.')
	{
		ptr->map[ptr->i][ptr->j] = 0;
		ptr->k += 2;
		ptr->j++;
	}
	if (ptr->read[ptr->k] == '0')
	{
		ptr->map[ptr->i][ptr->j] = 0;
		ptr->player_i = ptr->i;
		ptr->player_j = ptr->j;
		ptr->k += 2;
		ptr->j++;
	}
}
