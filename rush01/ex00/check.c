/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:15:10 by siykim            #+#    #+#             */
/*   Updated: 2022/02/13 21:15:23 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_colup(int co[2], int arr[9][9], int value, int size)
{
	int	i;
	int	count;
	int	max;

	i = 0;
	count = 1;
	max = arr[0][co[1]];
	while (i <= co[0])
	{
		if (max < arr[i][co[1]])
		{
			max = arr[i][co[1]];
			count++;
		}
		i++;
	}
	if (count == value
		|| (count + ((size - 1) - co[0]) >= value && count < value))
		return (1);
	else
		return (0);
}

int	check_coldown(int co[2], int arr[9][9], int value, int size)
{
	int	i;
	int	count;
	int	max;

	if (co[0] != size - 1)
		return (1);
	i = size - 1;
	count = 1;
	max = arr[size - 1][co[1]];
	while (i >= 0)
	{
		if (max < arr[i][co[1]])
		{
			max = arr[i][co[1]];
			count++;
		}
		i--;
	}
	if (count == value)
		return (1);
	else
		return (0);
}

int	check_rowleft(int co[2], int arr[9][9], int value, int size)
{
	int	j;
	int	count;
	int	max;

	j = 0;
	count = 1;
	max = arr[co[0]][0];
	while (j <= co[1])
	{
		if (max < arr[co[0]][j])
		{
			max = arr[co[0]][j];
			count++;
		}
		j++;
	}
	if (count == value
		|| (count + ((size - 1) - co[1]) >= value && count < value))
		return (1);
	else
		return (0);
}

int	check_rowright(int co[2], int arr[9][9], int value, int size)
{
	int	j;
	int	count;
	int	max;

	if (co[1] != size - 1)
		return (1);
	j = size - 1;
	count = 1;
	max = arr[co[0]][size - 1];
	while (j >= 0)
	{
		if (max < arr[co[0]][j])
		{
			max = arr[co[0]][j];
			count++;
		}
		j--;
	}
	if (count == value)
		return (1);
	else
		return (0);
}

int	check_all(int co[2], int arr[9][9], int value[9][9], int size)
{
	if (check_colup(co, arr, value[0][co[1]], size) == 1 &&
		check_coldown(co, arr, value[1][co[1]], size) == 1 &&
		check_rowleft(co, arr, value[2][co[0]], size) == 1 &&
		check_rowright(co, arr, value[3][co[0]], size) == 1)
		return (1);
	return (0);
}
