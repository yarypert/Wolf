/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 15:23:48 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/20 20:06:25 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_hook(int keycode)
{
	if (keycode == 53 || keycode == 65307)
		exit(0);
	if (keycode == 46)
		{
			
		}
	return (0);
}

int		exit_cross(void)
{
	exit(0);
	return (0);
}
