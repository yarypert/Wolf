/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 08:11:06 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/20 18:57:36 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	border_check(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	ptr->map_char = ft_strsplit(ptr->read, '\n');
	border_check2(ptr, i, j);
	i = 0;
	while (i < ptr->line)
	{
		if (ptr->map_char[i][0] != 'X' ||
				ptr->map_char[i][ptr->column * 2 - 2] != 'X')
			ft_error("file not valid. (\"./Wolf3D --format for help\")\n");
		i++;
	}
}

void	border_check2(t_ptr *ptr, int i, int j)
{
	while (i == 0 || i == ptr->line - 1)
	{
		j = 0;
		while (j < ptr->column * 2 - 1)
		{
			if ((j % 2 == 1 && ptr->map_char[i][j] == 'X') ||
					(j % 2 == 0 && ptr->map_char[i][j] != 'X') ||
					(j % 2 == 0 && ptr->map_char[i][j] == ' ') ||
					(j % 2 == 1 && ptr->map_char[i][j] != ' '))
				ft_error("file not valid. (\"./Wolf3D --format for help\")\n");
			j++;
		}
		i += ptr->line - 1;
	}
}

void	check_middle(t_ptr *ptr)
{
	int i;
	int j;

	i = 1;
	while (i < ptr->line - 1)
	{
		j = 1;
		while (j < ptr->column * 2 - 3)
		{
			if (ptr->map_char[i][j] != '.' && ptr->map_char[i][j] != ' ' &&
					ptr->map_char[i][j] != '1' && ptr->map_char[i][j] != '0')
				ft_error("file not valid. (\"./Wolf3D --format for help\")\n");
			j++;
		}
		i++;
	}
}

void	parse(t_ptr *ptr)
{
	int i;

	i = 0;
	line_len(ptr);
	border_check(ptr);
	count_zero(ptr);
	ptr->map = ((int **)malloc(sizeof(int *) * (ptr->line)));
	while (i < ptr->line)
	{
		ptr->map[i] = ((int *)malloc((sizeof(int) * ptr->column)));
		i++;
	}
	check_middle(ptr);
	fill_tab(ptr);
	print_int_tab(ptr);
}
