/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:01:46 by siykim            #+#    #+#             */
/*   Updated: 2022/02/08 17:17:36 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	comparer(char *str, char *to_find, int to_find_len)
{
	int	i;

	i = 0;
	while (i < to_find_len)
	{
		if (str[i] != to_find[i])
			return (0);
		i++;
	}
	return (1);
}

int	length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (length(to_find) == 0)
		return (str);
	while (i < length(str))
	{
		if (str[i] == to_find[0])
		{
			if (comparer(&str[i], to_find, length(to_find)) == 1)
				return (&str[i]);
			if (str[i] == '\0')
				break ;
		}
		i++;
	}
	return (0);
}
