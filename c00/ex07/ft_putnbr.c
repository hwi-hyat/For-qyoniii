/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:55:19 by siykim            #+#    #+#             */
/*   Updated: 2022/02/05 17:55:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	reverser(char rev[11], int edge)
{
	char	out[11];
	 int	i;

	i = 0;
	while (edge >= 0)
	{
		out[i] = rev[edge];
		i++;
		edge--;
	}
	write(1, out, i);
}

void	printer(int n)
{
	char	rev[11];
	 int	edge;

	edge = 0;
	while (n != 0)
	{
		rev[edge] = n % 10 + 48;
		n /= 10;
		if (n == 0)
			break ;
		edge++;
	}
	reverser(rev, edge);
}

void	printer_neg(int n)
{
	char	rev[11];
	 int	edge;

	edge = 0;
	while (n != 0)
	{
		rev[edge] = -(n % 10) + 48;
		n /= 10;
		if (n == 0)
			break ;
		edge++;
	}
	edge++;
	rev[edge] = '-';
	reverser(rev, edge);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
		printer_neg(nb);
	else
		printer(nb);
}
