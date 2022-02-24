/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:08:08 by siykim            #+#    #+#             */
/*   Updated: 2022/02/06 14:08:10 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	x_printer_last1(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar('\\');
		else if (col == x - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
		col++;
	}
}

void	x_printer_first1(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0)
			ft_putchar('/');
		else if (col == x - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
		col++;
	}
}

void	x_printer1(int x)
{
	int	col;

	col = 0;
	while (col < x)
	{
		if (col == 0 || col == x - 1)
			ft_putchar('*');
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
			x_printer_first1(x);
		else if (row == y - 1)
			x_printer_last1(x);
		else
			x_printer1(x);
		ft_putchar('\n');
		row++;
	}
}
