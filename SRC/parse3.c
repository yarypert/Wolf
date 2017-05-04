/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:18:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/04 18:19:10 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	first_check(t_ptr *ptr)
{
	int i;

	i = 0;
	while (ptr->read[i])
	{
		if (ptr->read[i] != 'X' && ptr->read[i] != '.' &&
				ptr->read[i] != '1' && ptr->read[i] != '0' &&
				ptr->read[i] != 'X')
			ft_usage();
		i++;
	}
}
