#include "wolf.h"

int main(int argc, char **argv)
{
	t_ptr ptr;
	ptr.str = argv[1];

	if (argc == 2)
	{
		if (ft_strcmp(argv[1],"--map") == 0)
			ft_map();
		else if (ft_strcmp((argv[1]), "--format") == 0)
			ft_format();
		else if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 5] , ".wolf") == 0)
		{
			ptr.read = read_file(argv[1]);
			parse(&ptr);
		}
		else 
			ft_usage(&ptr);
	}
	else
		ft_usage(&ptr);
}
