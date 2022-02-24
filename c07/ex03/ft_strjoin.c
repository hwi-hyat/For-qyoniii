/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:20:08 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 12:20:10 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *c)
{
	int	len;

	len = 0;
	while (c[len] != 0)
		len++;
	return (len);
}

void	writer(char *str, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		str[i] = src[i];
		i++;
	}
}

char	*filler(char **strs, char *sep, int size, int mallocsize)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	out = (char *)malloc(sizeof(char) * mallocsize);
	while (j < size)
	{
		writer(&out[i], strs[j]);
		i += ft_strlen(strs[j]);
		if (i == mallocsize - 1)
			break ;
		writer(&out[i], sep);
		i += ft_strlen(sep);
		j++;
	}
	out[i] = 0;
	return (out);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		i;
	int		mallocsize;

	if (size == 0)
	{
		out = malloc(1);
		out[0] = 0;
		return (out);
	}
	i = 0;
	mallocsize = 0;
	while (i < size)
	{
		mallocsize += ft_strlen(strs[i]);
		if (i == size - 1)
			break ;
		mallocsize += ft_strlen(sep);
		i++;
	}
	mallocsize++;
	return (filler(strs, sep, size, mallocsize));
}
