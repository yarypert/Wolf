/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 18:06:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/23 18:16:13 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	weapons_info(t_ptr *ptr)
{
	ak_info(ptr);
	de_info(ptr);
}

void	ak_info(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 100, 100 ,0xFFFFFF,ft_itoa(ptr->ak_mag));
	mlx_string_put(ptr->mlx, ptr->win, 80, 100 ,0xFFFFFF,"AK");
}

void	de_info(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 100, 200 ,0xFFFFFF,ft_itoa(ptr->de_mag));
	mlx_string_put(ptr->mlx, ptr->win, 80, 200 ,0xFFFFFF,"DE");
}
