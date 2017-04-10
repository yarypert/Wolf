#include "wolf.h"

void	ft_usage(t_ptr *ptr)
{
	ft_putstr("usage : Wolf3D <map_name>\n\
 Options :\n\
  --format : displays instructions about the maps.\n\
  --map : shows exemples of maps.\n");
	exit(0);
}


void	ft_format(void)
{
	ft_putstr("\n*** MAP FORMAT :\n\n\
  - Map must contain only 'X', '.', '1', '0' or ' '.\n\
  - 0 is the player's starting position, place only one.\n\
  - Walls are designed with 1.\n\
  - Map is delimited with a X border.\n\
  - Map has to be a rectangle.\n\
  - Each characters has to be followed by a ' ',\
except for the last characters who has to be followed by a '\\n'.\n\n");
	exit(0);
}

void	ft_map(void)
{
	ft_putstr("\n*** EXEMPLES OF MAPS :\n\n\
  ** VALID MAPS :\n\n	X X X X X X X X\n\
	X . . . . . . X\n	X . . . 0 . . X\n	X . . . . . . X\n\
	X X X X X X X X\n\n	X X X X X X X X\n	X 1 1 . . 1 1 X\n\
	X . 1 . 0 . 1 X\n	X . . . 1 . . X\n	X X X X X X X X\n\n\
  ** INVALID MAPS :\n\n\
	. . . . 1 . 1 .\n	. . . . 1 . 1 .\n	. 1 . . 0 . 1 .\n\
	. 1 . . 1 1 1 .\n	. . 1 . . . . .\n\n\
	X X X X X X X X\n	X . . . . . . X\n	X . 1 1 . 1 1 X\n\
	X . 1 . . 1 . X\n	X X X X X X X X\n\n	X X X X X X X X\n\
	X . . 1 . . . X\n	X . . . . X X X\n	X 1 1 0 . X    \n\
	X . 1 . . X X X\n	X . 1 . . . . X\n	X X X X X X X X\n\n");
	exit(0);
}
