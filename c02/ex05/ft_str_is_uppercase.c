/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:05:57 by siykim            #+#    #+#             */
/*   Updated: 2022/02/09 00:05:58 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	upr(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	else
		return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			return (1);
		else if (upr(str[i]) == 0)
			return (0);
		i++;
	}
}
