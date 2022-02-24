/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 10:50:05 by siykim            #+#    #+#             */
/*   Updated: 2022/02/21 09:57:29 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	num_size(int num)
{
	int	deci;

	deci = 1;
	while (num / 10 != 0)
	{
		num /= 10;
		deci *= 10;
	}
	return (deci);
}

void	ft_putnum(int num)
{
	int	deci;
	int	out;

	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (num < 0)
		write(1, "-", 1);
	deci = num_size(num);
	while (deci != 0)
	{
		out = num / deci;
		if (out < 0)
			out *= -1;
		out += 48;
		write(1, &out, 1);
		num = num % deci;
		deci /= 10;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		write(1, par[i].str, str_len(par[i].str));
		write(1, "\n", 1);
		ft_putnum(par[i].size);
		write(1, "\n", 1);
		write(1, par[i].copy, str_len(par[i].copy));
		write(1, "\n", 1);
		i++;
	}
}
