/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:04:12 by siykim            #+#    #+#             */
/*   Updated: 2022/02/06 14:06:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	x_printer_edge0(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('o');
		else
			ft_putchar('-');
		col++;
	}
}

void	x_printer0(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('|');
		else
			ft_putchar(' ');
		col++;
	}
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 0;
	while (row < y)
	{
		if (row == 0 || row == y - 1)
			x_printer_edge0(x);
		else
			x_printer0(x);
		ft_putchar('\n');
		row++;
	}
}
