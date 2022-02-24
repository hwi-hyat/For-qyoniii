/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:49:56 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 10:49:58 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*arr;

	arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < ac)
	{
		arr[i].size = str_len(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].str = 0;
	return (arr);
}
