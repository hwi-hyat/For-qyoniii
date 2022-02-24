/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinypark <jinypark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:56:22 by jinypark          #+#    #+#             */
/*   Updated: 2022/02/20 21:21:47 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "h.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_dup_strcat_space(char *dest, char *src)
{
	char	*result;
	int		idx;
	int		idx2;

	if (!*dest || !*src)
		result = (char *)malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	else
		result = (char *)malloc(ft_strlen(dest) + ft_strlen(src) + 2);
	idx = 0;
	idx2 = 0;
	while (dest[idx])
		result[idx2++] = dest[idx++];
	if (*dest && *src)
		result[idx2++] = ' ';
	idx = 0;
	while (src[idx])
		result[idx2++] = src[idx++];
	result[idx2] = '\0';
	return (result);
}

int	arr_big_len(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len % 3)
		len = len / 3 + 1;
	else
		len = len / 3;
	return (len);
}
