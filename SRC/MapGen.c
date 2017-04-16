#include "wolf.h"

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

void	place_player(t_gen *gen)
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
			if (gen->rand < 1 && gen->map[i][j] == '.')
			{
				gen->map[i][j] = '0';
				return ;
			}
			j+=2;
		}
		i++;
	}
	place_player(gen);
}

void	place_wall(t_gen *gen)
{
	int i;
	int j;

	i = 0;
	j = 0;
	gen->rand = rand() % 4;
	while (i < gen->line - 1)
	{
		while(j < gen->column * 2 - 2)
		{
			if(gen->map[i][j] == '1')
			{
				if(i - 1 > 0 && gen->map[i - 1][j] == '.' && gen->rand == 0)

				if(i + 1 < gen->line && gen->map[i + 1][j] == '.' && gen->rand == 1)
				
				if(j - 2 > 0 && gen->map[i][j - 2] == '.' && gen->rand == 2)
				
				if(j + 2 < gen->column && gen->map[i][j + 2] == '.' && gen->rand == 3)
			
			}
		}
	}
}

void	create_map(t_gen *gen)
{
	alloc_map(gen);
	fill_map_walls(gen);
	place_player(gen);
	print(gen);
}

int main(int argc, char **argv)
{
	t_gen gen;
	unsigned seed;

	read(open("/dev/urandom", O_RDONLY), &seed, sizeof seed);
	srand(seed);


	if(argc == 4)
	{
		gen.line = ft_atoi(argv[1]);
		gen.column = ft_atoi(argv[2]);
		gen.percent = ft_atoi(argv[3]);
		if (gen.percent < 0 || gen.percent > 100 || gen.column > 50 || gen.line > 50 || gen.line < 3 || gen.column < 3)
			ft_error("USAGE\n");
		create_map(&gen);
	}
	else
		ft_error("USAGE\n");
	return (0);
}
