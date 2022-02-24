/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:06:04 by siykim            #+#    #+#             */
/*   Updated: 2022/02/12 03:06:06 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	translator(int nbr, char *base, int len, int neg)
{
	 int	i;
	char	out[33];

	i = 32;
	while (i >= 0)
	{
		if (nbr == 0 && nbr % len == 0)
		{
			if (neg)
			{
				out[i] = '-';
				i--;
			}
			break ;
		}
		if (neg == 0)
			out[i] = base[nbr % len];
		else
			out[i] = *(base - (nbr % len));
		nbr /= len;
		i--;
	}
	write(1, &out[i + 1], 32 - i);
}

int	base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;
	int	neg;

	if (nbr == 0)
		write(1, &base[0], 1);
	if (base_check(base) == 0)
		return ;
	len = 0;
	while (base[len] != 0)
		len++;
	if (len <= 1)
		return ;
	neg = 0;
	if (nbr < 0)
		neg++;
	translator(nbr, base, len, neg);
}
