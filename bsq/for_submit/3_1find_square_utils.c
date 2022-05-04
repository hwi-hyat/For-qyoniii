#include "ajtcsheader.h"

void	is_it_max(t_start co, int size, t_max *max)
{
	if (size > max->max_size)
	{
		max->max_y = co.y;
		max->max_x = co.x;
		max->max_size = size;
	}
}

int	val_map_acc(t_start co, int size, t_info *map_info)
{
	if ((co.y + size) == map_info->tall || (co.x + size) == map_info->len)
		return (2);
	else if ((co.y + size) < map_info->tall || (co.x + size) < map_info->len)
		return (1);
	return (0);
}

void	printer(char **map, t_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->tall)
	{
		j = 0;
		while (j < map_info->len)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
