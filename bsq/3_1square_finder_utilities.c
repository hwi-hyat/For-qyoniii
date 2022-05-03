/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_finder_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:12:26 by siykim            #+#    #+#             */
/*   Updated: 2022/02/24 00:12:26 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myheader.h"

int	obs_chk(char c, t_info *map_info)
{
	if (c == map_info->obs)
		return (0);
	return (1);
}

void	is_it_max(t_start co, int size, t_max *max_sq)
{
	if (size > max_sq->max_size)
	{
		max_sq->max_y = co.y;
		max_sq->max_x = co.x;
		max_sq->max_size = size;
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
