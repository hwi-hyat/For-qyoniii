/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:08:36 by siykim            #+#    #+#             */
/*   Updated: 2022/02/06 17:40:42 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	x_printer_last2(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		col++;
	}
}

void	x_printer_first2(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		col++;
	}
}

void	x_printer2(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('B');
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
		if (row == 0)
			x_printer_first2(x);
		else if (row == y - 1)
			x_printer_last2(x);
		else
			x_printer2(x);
		ft_putchar('\n');
		row++;
	}
}
