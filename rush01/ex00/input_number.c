/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:15:30 by siykim            #+#    #+#             */
/*   Updated: 2022/02/13 21:15:31 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_all(int co[2], int arr[9][9], int value[9][9], int size);

int	allocate_num(int co[2], int arr[9][9], int start_num, int size)
{
	int	i;

	while (start_num <= size)
	{
		i = 0;
		while (i < size)
		{
			if (start_num == arr[i][co[1]])
				break ;
			else if (start_num == arr[co[0]][i])
				break ;
			i++;
		}
		if (i == size)
			return (start_num);
		start_num++;
	}
	return (-1);
}

void	olim(int *co0, int *co1)
{
	*co1 += 1;
	*co0 = 0;
}

int	input_number(int co[2], int arr[9][9], int value[9][9], int size)
{	
	int	number;
	int	ret_val;
	int	co_ad[2];

	ret_val = 0;
	if (co[1] >= size - 1 && co[0] > size - 1)
		return (1);
	if (co[0] > size - 1)
		olim(co, co + 1);
	number = allocate_num(co, arr, 1, size);
	if (number == -1)
		return (0);
	co_ad[0] = co[0] + 1;
	co_ad[1] = co[1];
	while (number != -1)
	{
		arr[co[0]][co[1]] = number;
		if (check_all(co, arr, value, size) == 1)
			ret_val = input_number(co_ad, arr, value, size);
		if (ret_val == 1)
			return (ret_val);
		number = allocate_num(co, arr, number + 1, size);
	}
	arr[co[0]][co[1]] = 0;
	return (ret_val);
}
