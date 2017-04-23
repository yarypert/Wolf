/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:16:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/04/23 19:25:37 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define SIZE_X 1000
# define SIZE_Y 1000

typedef struct	s_ptr
{
	int init;

	int		flag_map;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		i;
	int		j;
	int		k;
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
	char	**map_char;
	int		**map;
	int		player_i;
	int		player_j;
	int		ak_mag;
	int		ak_mode;
	int		de_mag;
	int		weapon_id;
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



void	ptr_init(t_ptr *ptr);
char	*ft_strappend(char *str1, char *str2);
char	*read_file(char *file);
void	draw_image(t_ptr ptr);
void	parse(t_ptr *ptr);
void	line_len(t_ptr *ptr);
void	count_zero(t_ptr *ptr);
void	fill_tab(t_ptr *ptr);
void	fill_tab2(t_ptr *ptr);
void	ft_usage(void);
void	ft_map(void);
void	ft_format(void);
void	border_check(t_ptr *ptr);
void	border_check2(t_ptr *ptr, int i, int j);
void	check_middle(t_ptr *ptr);
void	first_check(t_ptr *ptr);
int		key_hook(int keycode,t_ptr *ptr);
int		exit_cross(void);
void	print_int_tab(t_ptr *ptr);
int		refresh(t_ptr *ptr);
int		mouse(int keycode, int x, int y, t_ptr *ptr);
void	ak_info(t_ptr *ptr);
void	de_info(t_ptr *ptr);
void	weapons_info(t_ptr *ptr);
int		wolf_mouse_manager(int x,int y, t_ptr *ptr);

void	line(t_ptr *ptr, int color);
void	mlx_pix_img(t_ptr *ptr, int x,int y, int color);
void	line_init(t_init *i, t_ptr ptr);
void	draw_square(t_ptr *ptr, int x, int y, int color);
void	draw_map(t_ptr *ptr);

#endif
