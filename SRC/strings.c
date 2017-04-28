/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 18:06:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/28 06:50:51 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	weapons_info(t_ptr *ptr)
{
	ak_info(ptr);
	de_info(ptr);
	mlx_string_put(ptr->mlx, ptr->win, 50, 595, 0xFFFFFF, "Pseudo :");
	mlx_string_put(ptr->mlx, ptr->win, 135, 595, 0xFFFFFF, ptr->name);
}

void	ak_info(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 325, 595, 0xFFFFFF,ft_itoa(ptr->ak_mag));
	mlx_string_put(ptr->mlx, ptr->win, 250, 595, 0xFFFFFF,"AK 47     /");
	mlx_string_put(ptr->mlx, ptr->win, 375, 595, 0xFFFFFF,ft_itoa(ptr->ak_max));
}

void	de_info(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 395, 630, 0xFFFFFF,ft_itoa(ptr->de_mag));
	mlx_string_put(ptr->mlx, ptr->win, 250, 630, 0xFFFFFF,"Desert Eagle     / 9");
}
