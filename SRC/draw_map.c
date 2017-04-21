/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:45:30 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/21 19:37:39 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_map(t_ptr *ptr)
{
	int i;
	int j;
	int color;
	i = 0;
	while (i < ptr->i)
	{
	j = 0;
		while (j < ptr->j)
		{
			if (ptr->map[i][j] == 1)
				color = 0x444444;
			if (ptr->map[i][j] == 0 && (i != ptr->player_i || j != ptr->player_j))
				color = 0x888888;
			if (i == ptr->player_i && j == ptr->player_j)
				color = 0xFF0000;
			draw_square(ptr, j * ((SIZE_X - 200) / ptr->j) + ((SIZE_X - 200)/ ptr->j) + 100, i * ((SIZE_Y - 200)/ ptr->i) + ((SIZE_Y - 200)/ ptr->i) + 100, color);
			j++;
		}
		i++;
	}
}

void	draw_square(t_ptr *ptr,int x, int y, int color)
{
	int i;
	int j;

	i = 0;
	while (i < ((SIZE_X - 200) / ptr->i))
	{
		ptr->x1 = x - ((SIZE_X - 200) / ptr->j);
		ptr->y1 = y - ((SIZE_Y - 200) / ptr->i) + i;
		ptr->x2 = x + ((SIZE_X - 200) / ptr->j) - ((SIZE_X - 200) / ptr->j);
		ptr->y2 = y - ((SIZE_Y - 200) / ptr->i) + i;
		line(ptr, color);
		i++;
	}
}
