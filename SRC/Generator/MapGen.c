#include "wolf.h"
#include <stdio.h>

void	alloc_map(t_gen *gen)
{
	int i;
	i = 0;
	gen->map = ((char **)malloc(sizeof(char *) * (gen->line)));
	while (i < gen->line)
	{
		gen->map[i] = ((char *)malloc(sizeof(char) * (gen->column * 2 -1)));
		i++;
	}
	gen->str_map = ((char *)malloc((sizeof(char) * gen->column * 2) * gen->line));
}

void	fill_map_walls(t_gen *gen)
{
	int i;
	int j;

	i = 0;
	while(i < gen->line)
	{
		j = 0;
		while(j < gen->column * 2)
		{
			if(i == 0 || i == gen->line - 1 || j == 0 || j == gen->column * 2 - 2)
				gen->map[i][j] = 'X';
			else
				gen->map[i][j] = '.';
			gen->map[i][j + 1] = ' ';
			j+=2;
		}
		gen->map[i][gen->column * 2 - 1] = '\0';
		i++;
	}
}

void	print(t_gen *gen)
{
	int i;

	i = 0;
	while(i < gen->line)
	{
		ft_putendl(gen->map[i]);
		i++;
	}
}

void	place_player(t_gen *gen, char c)
{
	int i;
	int j;

	i = 1;
	while (i < gen->line - 1)
	{
		j = 2;
		while (j < gen->column * 2 - 2)
		{
			gen->rand = rand() % 1000;
			if (gen->rand < 1 && gen->map[i][j] == '.' && gen->map[i][j] != '0')
			{
				gen->map[i][j] = c;
				return ;
			}
			j+=2;
		}
		i++;
	}
	place_player(gen, c);
}

void	cond_walls(t_gen *gen,int i,int j)
{
	if(gen->map[i][j] == '1')
	{
		if(i - 1 > 0 && gen->map[i - 1][j] == '.' && gen->rand == 0)
			gen->map[i][j] = '0';
		if(i + 1 < gen->line && gen->map[i + 1][j] == '.' && gen->rand == 1)
			gen->map[i][j] = '0';
		if(j - 2 > 0 && gen->map[i][j - 2] == '.' && gen->rand == 2)
			gen->map[i][j] = '0';
		if(j + 2 < gen->column && gen->map[i][j + 2] == '.' && gen->rand == 3)
			gen->map[i][j] = '0';
	}
}

void	place_wall(t_gen *gen)
{
	int i;
	int j;

	i = 0;
	gen->rand = rand() % 4;
	while (i < gen->line - 1)
	{
		j = 0;
		while(j < gen->column * 2 - 2)
		{
			cond_walls(gen,i , j);
			j++;
		}
		i++;
	}
}

void	last_check(t_gen *gen, char a, char b,char c)
{
	int i;
	int j;

	i = 1;
	gen->link = 0;
	while (i < gen->line - 1)
	{
		j = 1;
		while(j < gen->column * 2 - 2)
		{
			if(gen->map[i][j] == a)
			{
				if ((gen->map[i - 1][j] == b || gen->map[i - 1][j] == c) 
						&& (gen->map[i + 1][j] == b || gen->map[i + 1][j] == c) 
						&& (gen->map[i][j - 2] == b || gen->map[i][j - 2] == c) 
						&& (gen->map[i][j + 2] == b || gen->map[i][j + 2] == c))
					gen->map[i][j] = b;
			}
			j++;
		}
		i++;
	}
}

void	tab_to_str(t_gen *gen)
{
	int i;
	
	i = 0;
	while (i < gen->line)
	{
		gen->str_map = ft_strjoin(gen->str_map, gen->map[i]);
		gen->str_map = ft_strjoin(gen->str_map, "\n");
		i++;
	}
}

void	put_to_file(t_gen *gen)
{
	int fd;
	gen->map = gen->map;
	fd = open("GenMap.wolf", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	ft_putstr_fd(gen->str_map,fd);
	if (fd == -1)
		ft_error("open() error");
	if(close(fd) == -1)
	{
		ft_error("close() error");
	}
}

void	create_map(t_gen *gen)
{
	int i = 0;
	int val;

	val = (gen->percent * ((gen->line - 2) * (gen->column - 2) - 1)) / 100;

	alloc_map(gen);
	fill_map_walls(gen);
	while (i < val)
	{
		place_player(gen, '1');
		i++;
	}
	last_check(gen, '1', '.', 'X');
	last_check(gen, '.', '1', 'X');
	place_player(gen, '0');
	tab_to_str(gen);
	put_to_file(gen);
}

int main(int argc, char **argv)
{
	t_gen gen;
	unsigned int seed;

	read(open("/dev/urandom", O_RDONLY), &seed, sizeof seed);
	srand(seed);
	if(argc == 4)
	{
		gen.line = ft_atoi(argv[1]);
		gen.column = ft_atoi(argv[2]);
		gen.percent = ft_atoi(argv[3]);
		if (gen.percent < 0 || gen.percent > 42 || gen.column > 50 || gen.line > 50 || gen.line <= 4 || gen.column <= 4)
			ft_error("USAGE\n");
		create_map(&gen);
	}
	else
		ft_error("USAGE\n");
	return (0);
}