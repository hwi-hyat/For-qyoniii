/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:13:56 by siykim            #+#    #+#             */
/*   Updated: 2022/02/15 01:13:58 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime07(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i * i <= (unsigned int)nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (2);
	if (nb == 2147483647)
		return (nb);
	i = nb;
	while (i <= 2147483647)
	{
		if (ft_is_prime07(i))
			return (i);
		i++;
	}
	return (0);
}
