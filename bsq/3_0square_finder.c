/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0square_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:09:24 by siykim            #+#    #+#             */
/*   Updated: 2022/02/24 01:37:44 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	sq_check(char **map, t_info *map_info, t_max *max_sq, int co[2])
{
	int	i;
	int	size;

	size = 1;
	while (val_map_acc(co, size, map_info))
	{
		i = 0;
		while (i < size && val_map_acc(co, size, map_info))
		{
			if (obs_chk(map[co[0] + size - 1][co[1] + i], map_info) == 0
				|| obs_chk(map[co[0] + i][co[1] + size - 1], map_info) == 0)
			{
				is_it_max(co, size - 1, max_sq);
				return ;
			}
			i++;
		}
		if (val_map_acc(co, size, map_info) == 2)
		{
			is_it_max(co, size, max_sq);
			return ;
		}
		size++;
	}
}

void	finder(char **map, t_info *map_info, t_max *max_sq)
{
	int	i;
	int	j;
	int	co[2];

	i = 0;
	while (i < (map_info->len - max_sq->max_size))
	{
		co[0] = i;
		j = 0;
		while (j < (map_info->wid - max_sq->max_size))
		{
			co[1] = j;
			sq_check(map, map_info, max_sq, co);
			j++;
		}
		i++;
	}
	return ;
}

void	square_filler(char **map, t_max *max_sq, t_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_sq->max_size)
	{
		j = 0;
		while (j < max_sq->max_size)
		{
			map[max_sq->start_y + i][max_sq->start_x + j] = map_info->full;
			j++;
		}
		i++;
	}
}

void	finder_main(char **map, t_info *map_info)
{	
	t_max	max_sq;

	max_sq.start_x = 0;
	max_sq.start_y = 0;
	max_sq.max_size = 0;
	finder(map, map_info, &max_sq);
	square_filler(map, &max_sq, map_info);
	printer(map, map_info);
}
