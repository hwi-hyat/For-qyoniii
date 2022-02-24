/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:39:50 by siykim            #+#    #+#             */
/*   Updated: 2022/02/12 02:40:52 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	out;

	i = 0;
	out = 0;
	neg = 0;
	while ((9 <= str[i] && str[i] <= 15) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while (48 <= str[i] && str[i] < 58)
	{
		out *= 10;
		out += str[i] - 48;
		i++;
	}
	if (neg % 2)
		out *= -1;
	return (out);
}
