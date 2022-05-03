/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_0square_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:09:24 by siykim            #+#    #+#             */
/*   Updated: 2022/05/03 23:38:49 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

void	sq_check(char **map, t_info *info, t_max *max_sq, t_start co)
{
	int	i;
	int	size;

	size = 1;
	while (val_map_acc(co, size, info))
	{
		i = 0;
		while (i < size && val_map_acc(co, size, info))
		{
			if (map[co.y + size - 1][co.x + i] == info->obs
				|| map[co.y + i][co.x + size - 1] == info->obs)
			{
				is_it_max(co, size - 1, max_sq);
				return ;
			}
			i++;
		}
		if (val_map_acc(co, size, info) == 2)
		{
			is_it_max(co, size, max_sq);
			return ;
		}
		size++;
	}
}

void	finder(char **map, t_info *info, t_max *max_sq)
{
	int		i;
	int		j;
	t_start	co;

	i = 0;
	while (i < (info->tall - max_sq->max_size))
	{
		co.y = i;
		j = 0;
		while (j < (info->len - max_sq->max_size))
		{
			co.x = j;
			sq_check(map, info, max_sq, co);
			j++;
		}
		i++;
	}
	return ;
}

void	square_filler(char **map, t_max *max_sq, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < max_sq->max_size)
	{
		j = 0;
		while (j < max_sq->max_size)
		{
			map[max_sq->max_y + i][max_sq->max_x + j] = info->fill;
			j++;
		}
		i++;
	}
}

void	finder_main(char **map, t_info *info)
{	
	t_max	max_sq;

	max_sq.max_x = 0;
	max_sq.max_y = 0;
	max_sq.max_size = 0;
	finder(map, info, &max_sq);
	square_filler(map, &max_sq, info);
	printer(map, info);
}
