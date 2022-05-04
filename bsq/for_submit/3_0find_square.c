#include "ajtcsheader.h"

void	sq_check(char **map, t_info *info, t_max *max, t_start co)
{
	int	i;
	int	size;

	size = 1;
	while (val_map_acc(co, size, info))
	{
		i = 0;
		while (i < size)
		{
			if (map[co.y + size - 1][co.x + i] == info->obs
				|| map[co.y + i][co.x + size - 1] == info->obs)
			{
				is_it_max(co, size - 1, max);
				return ;
			}
			i++;
		}
		if (val_map_acc(co, size, info) == 2)
		{
			is_it_max(co, size, max);
			return ;
		}
		size++;
	}
}

void	finder(char **map, t_info *info, t_max *max)
{
	t_start	co;

	co.y = 0;
	while (co.y < (info->tall - max->max_size))
	{
		co.x = 0;
		while (co.x < (info->len - max->max_size))
		{
			sq_check(map, info, max, co);
			co.x++;
		}
		co.y++;
	}
	return ;
}

void	square_filler(char **map, t_max *max, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < max->max_size)
	{
		j = 0;
		while (j < max->max_size)
		{
			map[max->max_y + i][max->max_x + j] = info->fill;
			j++;
		}
		i++;
	}
}

void	finder_main(char **map, t_info *info)
{	
	t_max	max;

	max.max_x = 0;
	max.max_y = 0;
	max.max_size = 0;
	finder(map, info, &max);
	square_filler(map, &max, info);
	printer(map, info);
}
