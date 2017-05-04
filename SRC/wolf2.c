/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 19:06:34 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 19:07:51 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_wolf6(t_ptr *ptr)
{
	ptr->ray.color = 0x00FF00FF;
	if (ptr->ray.side == 0)
		ptr->ray.color = (ptr->ray.stepx == -1 ? RED : YELLOW);
	else
		ptr->ray.color = (ptr->ray.stepy == -1 ? BLUE : GREEN);
	if (ptr->ray.side == 1)
		ptr->ray.color = ptr->ray.color / 2;
	ptr->x1 = ptr->ray.i;
	ptr->y1 = ptr->ray.drawstart;
	ptr->x2 = ptr->ray.i;
	ptr->y2 = ptr->ray.drawend;
	line(ptr, ptr->ray.color);
	ptr->x1 = ptr->ray.i;
	ptr->y1 = ptr->ray.drawstart;
	ptr->x2 = ptr->ray.i;
	ptr->y2 = 0;
	line(ptr, 0x00444444);
	ptr->x1 = ptr->ray.i;
	ptr->y1 = SIZE_Y;
	ptr->x2 = ptr->ray.i;
	ptr->y2 = ptr->ray.drawend;
	line(ptr, 0x00999999);
}
