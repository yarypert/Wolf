/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 07:31:35 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/20 19:00:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapgen.h"

void	ft_usage(void)
{
	ft_putendl("Usage : ./MapGenerator \033[38;5;160m<line_number> \
<column_number> <filling_percentage>\033[0m");
	ft_putendl("  \033[38;5;40m~\033[0m Line_number must be equal \
to Column_number");
	ft_putendl("  \033[38;5;40m~\033[0m Line_number must be between 5 and 50.");
	ft_putendl("  \033[38;5;40m~\033[0m Column_number must be between \
5 and 50.");
	ft_putendl("  \033[38;5;40m~\033[0m Filling_percentage \
must be between 0 and 42.");
	exit(0);
}
