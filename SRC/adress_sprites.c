/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 16:25:19 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 19:38:55 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_adress(t_ptr *ptr)
{
	ptr->bts = mlx_get_data_addr(ptr->img, &(ptr->bpp), &(ptr->size_line),
			&(ptr->endian));
	ptr->sprt.logoad = mlx_get_data_addr(ptr->sprt.logo, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.menuad = mlx_get_data_addr(ptr->sprt.menu, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.akwepad = mlx_get_data_addr(ptr->sprt.akwep, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.dewepad = mlx_get_data_addr(ptr->sprt.dewep, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.de01ad = mlx_get_data_addr(ptr->sprt.de01, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.de02ad = mlx_get_data_addr(ptr->sprt.de02, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.ak01ad = mlx_get_data_addr(ptr->sprt.ak01, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.ak02ad = mlx_get_data_addr(ptr->sprt.ak02, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.akbulad = mlx_get_data_addr(ptr->sprt.akbul, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
	ptr->sprt.debulad = mlx_get_data_addr(ptr->sprt.debul, &ptr->bpp,
			&ptr->size_line, &ptr->endian);
}
