/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:38:27 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 19:01:11 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	print_int_tab(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	while (i < ptr->line)
	{
		j = 0;
		while (j < ptr->column)
		{
			ft_putnbr(ptr->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
