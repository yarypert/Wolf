#include "wolf.h"

void	draw_image(t_ptr ptr)
{
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, SIZE_X, SIZE_Y, ptr.read);
	ptr.img = mlx_new_image(ptr.mlx, SIZE_X, SIZE_Y);
	ptr.bts = mlx_get_data_addr(ptr.img, &(ptr.bpp), &(ptr.size_line), &(ptr.endian));
	
	mlx_put_image_to_window(ptr.mlx, ptr.win, ptr.img, 0, 0);
	mlx_loop(ptr.mlx);
}
