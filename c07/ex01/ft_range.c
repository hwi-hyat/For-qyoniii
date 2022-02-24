/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:19:57 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 17:09:54 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	long long		size;
	long long		i;
	int				*out;

	if (min >= max)
		return (0);
	size = max - min;
	out = malloc(sizeof(int) * size);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		out[i] = min;
		i++;
		min++;
	}
	return (out);
}
