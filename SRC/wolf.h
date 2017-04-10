/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:16:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/03/20 22:26:14 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define SIZE_X 800
# define SIZE_Y 800
# define TEST ft_putchar('a');

typedef struct	s_ptr
{
	int init;

	int		bpp;
	char	*bts;
	int		size_line;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	int		line;
	int		column;
	char	*str;
	char	*read;
	int		**map;
	int		player_i;
	int		player_j;
}				t_ptr;

typedef	struct	s_init
{
	int		dx;
	int		sx;
	int		dy;
	int		sy;
	int		err;
	int		e2;
}				t_init;

char	*ft_strappend(char *str1, char *str2);
char	*read_file(char *file);
void	draw_image(t_ptr ptr);
void	parse(t_ptr *ptr);
void	line_len(t_ptr *ptr);
void	print_int_tab(t_ptr *ptr);
void	count_zero(t_ptr *ptr);
void	fill_tab(t_ptr *ptr);
void	ft_usage(t_ptr *ptr);
void	ft_help(void);
void	ft_map(void);
void	ft_format(void);


#endif
