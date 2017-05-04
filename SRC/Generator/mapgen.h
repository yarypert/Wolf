/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 01:05:28 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/18 08:01:07 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPGEN_H
# define MAPGEN_H
# include "../Libft/libft.h"

typedef struct	s_gen
{
	int		line;
	int		column;
	int		percent;
	char	**map;
	char	*str_map;
	int		rand;
	int		link;
}				t_gen;

void			alloc_map(t_gen *gen);
void			fill_map_walls(t_gen *gen);
void			print(t_gen *gen);
void			place_player(t_gen *gen, char c);
void			cond_walls(t_gen *gen, int i, int j);
void			place_wall(t_gen *gen);
void			last_check(t_gen *gen, char a, char b, char c);
void			tab_to_str(t_gen *gen);
void			put_to_file(t_gen *gen);
void			create_map(t_gen *gen);
void			ft_usage(void);

#endif
