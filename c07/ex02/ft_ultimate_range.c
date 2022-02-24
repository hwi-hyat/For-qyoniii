/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:02 by siykim            #+#    #+#             */
/*   Updated: 2022/02/22 11:49:24 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long		size;
	long long		i;
	int				*arr;

	size = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i] = min;
		i++;
		min++;
	}
	*range = arr;
	return ((int)size);
}
