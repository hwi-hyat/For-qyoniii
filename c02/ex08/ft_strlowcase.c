/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 00:07:40 by siykim            #+#    #+#             */
/*   Updated: 2022/02/09 00:07:41 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	low(char c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		if (str[i] == '\0')
			break ;
		str [i] = low(str[i]);
		i++;
	}
	return (str);
}
