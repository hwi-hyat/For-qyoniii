/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:09:35 by siykim            #+#    #+#             */
/*   Updated: 2022/02/06 14:09:36 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	x_printer_last4(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar('C');
		else if (col == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		col++;
	}
}

void	x_printer_first4(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar('A');
		else if (col == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		col++;
	}
}

void	x_printer4(int x)
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
			x_printer_first4(x);
		else if (row == y - 1)
			x_printer_last4(x);
		else
			x_printer4(x);
		ft_putchar('\n');
		row++;
	}
}
