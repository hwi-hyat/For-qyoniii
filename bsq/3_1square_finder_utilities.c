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

void	is_it_max(int co[2], int size, t_max *max_sq)
{
	if (size > max_sq->max_size)
	{
		max_sq->start_y = co[0];
		max_sq->start_x = co[1];
		max_sq->max_size = size;
	}
}

int	val_map_acc(int co[2], int size, t_info *map_info)
{
	if ((co[0] + size) == map_info->len || (co[1] + size) == map_info->wid)
		return (2);
	else if ((co[0] + size) < map_info->len || (co[1] + size) < map_info->wid)
		return (1);
	return (0);
}

void	printer(char **map, t_info *map_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_info->len)
	{
		j = 0;
		while (j < map_info->wid)
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
