/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <yarypert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:16:45 by yarypert          #+#    #+#             */
/*   Updated: 2017/05/02 16:41:10 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "../MLX_FILES/mlx/mlx.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <time.h>

# define SIZE_X 700
# define SIZE_Y 700

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define YELLOW 0x0000FFFF

typedef	struct	s_ray
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayposX;
	double	rayposY;
	double	raydirX;
	double	raydirY;
	int		mapX;
	int		mapY;
	double	sidedistX;
	double	sidedistY;
	double	deltadistX;
	double	deltadistY;
	double	perpwalldist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	int		i;
	double olddirX;
	double oldplaneX;
}				t_ray;

typedef	struct	s_sprt
{
	int		sizex;
	int		sizey;
	void	*menu;
	char	*menuad;
	void	*akwep;
	char	*akwepad;
	void	*dewep;
	char	*dewepad;
	void	*ak01;
	char	*ak01ad;
	void	*ak02;
	char	*ak02ad;
	void	*de01;
	char	*de01ad;
	void	*de02;
	char	*de02ad;
	void	*akbul;
	char	*akbulad;
	void	*debul;
	char	*debulad;
}				t_sprt;

typedef struct	s_ptr
{
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
	int		ak_max;
	int		ak_mode;
	int		de_mag;
	int		weapon_id;
	char	*name;
	int		shot;
	t_sprt	sprt;
	t_ray	ray;
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
int		mouse2(int keycode, int x, int y, t_ptr *ptr);
void	weapons_info(t_ptr *ptr);
void	init_wolf(t_ptr *ptr);
void	init_wolf2(t_ptr *ptr);
void	init_wolf3(t_ptr *ptr);
void	init_wolf4(t_ptr *ptr);
void	init_wolf5(t_ptr *ptr);
int		move(int keycode, t_ptr *ptr);

void	ak_bullet(t_ptr *ptr);
int		tricks(int i);
void	create_images(t_ptr *ptr);
void	set_adress(t_ptr *ptr);
void	put_images(t_ptr *ptr);
void	destroy_images(t_ptr *ptr);
void	put_guns(t_ptr *ptr);
void	put_guns_fire(t_ptr *ptr);
int		refreshfire(t_ptr *ptr);
int		burst(t_ptr *ptr);

void	ray_init(t_ptr *ptr);
void	wolf(t_ptr *ptr);
void	line(t_ptr *ptr, int color);
void	mlx_pix_img(t_ptr *ptr, int x,int y, int color);
void	line_init(t_init *i, t_ptr ptr);
void	draw_square(t_ptr *ptr, int x, int y, int color);

#endif

