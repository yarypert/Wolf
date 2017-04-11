#include "wolf.h"

void	print_int_tab(t_ptr *ptr)
{
	int i;
	int j;

	i = 0;
	while (i < ptr->line)
	{
		j = 0;
		while (j < ptr->column)
		{
			ft_putnbr(ptr->map[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	line_len(t_ptr *ptr)
{
	int i;
	int flag;
	i = 0;
	flag = 0;
	ptr->line = 0;
	while (ptr->read[i] != '\0')
	{
		ptr->column = 0;
		while (ptr->read[i] != '\n' && ptr->read[i])
		{
			if ((ptr->read[i] == 'X' || ptr->read[i] == '.' || ptr->read[i] == '1' || ptr->read[i] == '0')  && (ptr->read[i + 1] == ' ' || ptr->read[i + 1] == '\n'))
				ptr->column++;
			i++;
		}
		if (flag == 0)
			flag = ptr->column;
		if (ptr->column != flag)
			ft_error("file not valid. (\"./Wolf3D --format\" for help)");
		ptr->line++;
		i++;
	}
}

void	count_zero(t_ptr *ptr)
{
	int player;
	int i;

	i = 0;
	player = 0;
	while (ptr->read[i])
	{
		if (ptr->read[i] == '0')
			player++;
		i++;
	}
	if (player != 1)
	{
		ft_putstr("Player count = ");
		ft_putnbr(player);
		ft_error(" , please set it to 1");
	}
}

void	fill_tab(t_ptr *ptr)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < ptr->line)
	{
		j = 0;
		while (j < ptr->column)
		{
			if (ptr->read[k] == ' ' || ptr->read[k] == '\n')
				k++;
			if (ptr->read[k] == 'X' || ptr->read[k] == '1')
			{
				ptr->map[i][j] = 1;
				k+=2;
				j++;
			}
			if (ptr->read[k] == '.')
			{
				ptr->map[i][j] = 0;
				k+=2;
				j++;
			}
			if (ptr->read[k] == '0')
			{
				ptr->map[i][j] = 0;
				ptr->player_i = i;
				ptr->player_j = i;
				k+=2;
				j++;
			}
		}
		i++;
	}
}

void	first_check(t_ptr *ptr)
{
	int i;

	i = 0;
	while (ptr->read[i])
	{
		if (ptr->read[i] != 'X' &&  ptr->read[i] != '.' &&  ptr->read[i] != '1' && ptr->read[i] != '0' && ptr->read[i] != 'X' )
			ft_usage;
		i++;
	}
}

void	border_check(t_ptr *ptr)
{
	char **map_char;
	int i;
	int j;

	i = 0;
	j = 0;
	map_char = ft_strsplit(ptr->read, '\n');








	while  (i < ptr->line)
	{
		ft_putstr(map_char[i]);
		ft_putchar('\n');
		i++;
	}
}

void	parse(t_ptr *ptr)
{
	int i;
	i = 0;
	line_len(ptr);
	border_check(ptr);
	count_zero(ptr);
	ptr->map = ((int **)malloc(sizeof(int *) * (ptr->line)));
	while (i < ptr->line)
	{
		ptr->map[i] = ((int *)malloc((sizeof(int) * ptr->column)));
		i++;
	}
	fill_tab(ptr);
}
