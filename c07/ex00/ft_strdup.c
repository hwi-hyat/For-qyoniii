/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:19:51 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 12:19:52 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	while (src[i] != 0)
		i++;
	out = (char *)malloc(sizeof(char) * i + 1);
	if (out == 0)
		return (0);
	j = 0;
	while (j != i)
	{
		out[j] = src[j];
		j++;
	}
	out[j] = '\0';
	return (out);
}
