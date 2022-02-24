/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:03:31 by siykim            #+#    #+#             */
/*   Updated: 2022/02/09 00:03:36 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	num(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			return (1);
		else if (num(str[i]) == 0)
			return (0);
		i++;
	}
}
