/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_arr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:15:46 by siykim            #+#    #+#             */
/*   Updated: 2022/02/13 21:52:04 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	printer(int arr[9][9], int size)
{
	 int	i;
	 int	j;
	char	c;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			c = arr[i][j] + 48;
			write(1, &c, 1);
			if (j != size - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	arr_initializer(int arr[9][9], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}	
}

int	str_to_int(char *str, int value[9][9], int size)
{
	int	row;
	int	str_idx;
	int	col;

	row = 0;
	str_idx = 0;
	col = 0;
	while (row < 4 && (str[str_idx] != '\0'))
	{
		if (str[str_idx] >= 49 && str[str_idx] < (49 + size))
		{
			value[row][col] = str[str_idx] - 48;
			col++;
			if (col >= size)
			{
				row++;
				col = 0;
			}
		}
		else if (str[str_idx] >= (49 + size) && str[str_idx] <= 57)
			return (0);
		str_idx++;
	}
	return (1);
}

int	str_len(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

int	input_checker(char *str)
{
	int	i;
	int	length;
	int	count;

	i = 0;
	count = 0;
	length = str_len(str);
	while (str[i] != '\0' && i < length)
	{
		if (str[i] >= 49 && str[i] <= 57)
			count++;
		else
			return (0);
		i += 2;
	}
	i = 1;
	while (i < length && str[i] != '\0')
	{
		if (str[i] != ' ' || str[length - 1] == ' ')
			return (0);
		i += 2;
	}
	if ((count % 4 == 0) && (((count / 4) >= 4) && ((count / 4) <= 7)))
		return (count / 4);
	return (0);
}
