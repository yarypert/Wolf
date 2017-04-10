#include "wolf.h"

char		*ft_strappend(char *str1, char *str2)
{
	char *tmp;

	if (str1 && str2)
	{
		tmp = ft_strjoin(str1, str2);
		free(str1);
		return(tmp);
	}
	return(NULL);
}

char		*read_file(char *file)
{
	int		fd;
	int		ret;
	char	str[BUFF_SIZE];
	char	*grid;

	grid = ft_strnew(1);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("Can't open file");
	while ((ret = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[ret]= '\0';
		grid = ft_strappend(grid, str);
	}
	if (ret == -1)
		ft_error("Can't read file");
	close(fd);
	return (grid);
}
