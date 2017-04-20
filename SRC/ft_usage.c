/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 02:13:00 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/20 18:56:41 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_usage(void)
{
	ft_putendl("Usage : ./Wolf3D \033[38;5;160m<map_name.wolf>\033[0m");
	ft_putendl("  Options :");
	ft_putendl("    \033[38;5;40m--format\033[0m : Displays instructions \
about the maps.");
	ft_putendl("    \033[38;5;40m--map\033[0m : Shows examples of maps.");
	exit(0);
}

void	ft_format(void)
{
	ft_putendl("\n\033[38;5;40m*** MAP FORMAT :\033[0m\n");
	ft_putendl("  \033[38;5;40m~\033[0m Map must be a square");
	ft_putendl("  \033[38;5;40m~\033[0m Map must contain only 'X', '.',\
'1', '0' or ' '.");
	ft_putendl("  \033[38;5;40m~\033[0m 0 is the player's starting position, \
place only one.");
	ft_putendl("  \033[38;5;40m~\033[0m Walls are designed with 1.");
	ft_putendl("  \033[38;5;40m~\033[0m Map is delimited with a X border.");
	ft_putendl("  \033[38;5;40m~\033[0m Map has to be a rectangle.");
	ft_putendl("  \033[38;5;40m~\033[0m Each characters has to be followed \
by a ' ', except for the last characters who has to be followed by a '\\n'.\n");
	exit(0);
}

void	ft_map(void)
{
	ft_putendl("\n\033[38;5;40m*** EXEMPLES OF MAPS :\033[0m\n");
	ft_putendl("   \033[38;5;28m** VALID MAPS :\033[0m\n\n	X X X X X X X X");
	ft_putendl("	X . . . . . . X\n	X . . . 0 . . X\n	X . . . . . . X");
	ft_putendl("	X X X X X X X X\n\n	X X X X X X X X\n	X 1 1 . . 1 1 X");
	ft_putendl("	X . 1 . 0 . 1 X\n	X . . . 1 . . X\n	X X X X X X X X\n");
	ft_putendl("   \033[38;5;28m** INVALID MAPS :\033[0m\n");
	ft_putendl("	. . . . 1 . 1 .\n	. . . . 1 . 1 .\n	. 1 . . 0 . 1 .");
	ft_putendl("	. 1 . . 1 1 1 .\n	. . 1 . . . . .\n");
	ft_putendl("	X X X X X X X X\n	X . . . . . . X\n	X . 1 1 . 1 1 X");
	ft_putendl("	X . 1 . . 1 . X\n	X X X X X X X X\n\n	X X X X X X X X");
	ft_putendl("	X . . 1 . . . X\n	X . . . . X X X\n	X 1 1 0 . X    ");
	ft_putendl("	X . 1 . . X X X\n	X . 1 . . . . X\n	X X X X X X X X\n");
	exit(0);
}
