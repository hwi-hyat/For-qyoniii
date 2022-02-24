/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:15:37 by siykim            #+#    #+#             */
/*   Updated: 2022/02/13 21:36:15 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	printer(int arr[9][9], int size);
void	arr_initializer(int arr[9][9], int size);
int		str_to_int(char *str, int value[9][9], int size);
int		minus_or_zero(char *str, int idx);
int		input_checker(char *str);
int		input_number(int co[2], int arr[9][9], int value[9][9], int size);

int	main(int argc, char *argv[])
{
	 int	value[9][9];
	 int	arr[9][9];
	 int	size;
	 int	co[2];

	if (argc != 2 || input_checker(argv[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	size = input_checker(argv[1]);
	str_to_int(argv[1], value, size);
	arr_initializer(arr, size);
	co[0] = 0;
	co[1] = 0;
	if (input_number(co, arr, value, size) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	printer(arr, size);
	return (0);
}
