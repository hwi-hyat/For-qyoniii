/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:16:43 by siykim            #+#    #+#             */
/*   Updated: 2022/02/15 01:16:48 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	checker(int board[10][10], int x, int y)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (board[i][x] == 1)
			return (0);
		if (x + i < 10 && y + i < 10)
			if (board[y + i][x + i] == 1)
				return (0);
		if (x + i < 10 && y - i >= 0)
			if (board[y - i][x + i] == 1)
				return (0);
		if (x - i >= 0 && y + i < 10)
			if (board[y + i][x - i] == 1)
				return (0);
		if (x - i >= 0 && y - i >= 0)
			if (board[y - i][x - i] == 1)
				return (0);
		i++;
	}
	return (1);
}

void	printer(int board[10][10])
{
	 int	i;
	 int	j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (board[i][j] == 1)
			{
				c = j + 48;
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

void	place(int board[10][10], int y, int *count)
{
	int	i;

	i = 0;
	if (y == 10)
	{
		*count += 1;
		printer(board);
		return ;
	}
	while (i < 10)
	{
		if (checker(board, i, y) == 1)
		{
			board[y][i] = 1;
			place(board, y + 1, count);
		}
		board[y][i] = 0;
		i++;
	}
	return ;
}

void	board_initializer(int board[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{	
	int	board[10][10];
	int	count;

	count = 0;
	board_initializer(board);
	place(board, 0, &count);
	return (count);
}
