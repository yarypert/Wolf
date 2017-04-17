/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapGen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:16:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/20 22:26:14 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPGEN_H
# define MAPGEN_H
# include "../Libft/libft.h"

typedef struct	s_gen
{
	int	line;
	int column;
	int percent;
	char **map;
	char *str_map;
	int rand;
	int link;
}				t_gen;

void	alloc_map(t_gen *gen);
void	fill_map_walls(t_gen *gen);
void	print(t_gen *gen);
void	place_player(t_gen *gen, char c);
void	cond_walls(t_gen *gen, int i, int j);
void	place_wall(t_gen *gen);
void	last_check(t_gen *gen, char a, char b, char c);
void	tab_to_str(t_gen *gen);
void	put_to_file(t_gen *gen);
void	create_map(t_gen *gen);


#endif
