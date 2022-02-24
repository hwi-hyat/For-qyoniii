/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:10:50 by siykim            #+#    #+#             */
/*   Updated: 2022/02/15 01:11:01 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	out;

	out = 1;
	if (index < 0)
		return (-1);
	if (index < 1)
		return (0);
	if (index == 1)
		return (1);
	out = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (out);
}
