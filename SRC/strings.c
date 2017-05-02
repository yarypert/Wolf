/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 18:06:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/01 21:35:15 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	weapons_info(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 50, 595, 0xFFFFFF, "Pseudo :");
	mlx_string_put(ptr->mlx, ptr->win, 135, 595, 0xFFFFFF, ptr->name);
}
