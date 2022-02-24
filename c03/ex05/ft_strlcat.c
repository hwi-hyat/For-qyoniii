/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:11:58 by siykim            #+#    #+#             */
/*   Updated: 2022/02/08 13:58:47 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	out;

	i = ft_strlen(dest);
	out = ft_strlen(dest);
	if (ft_strlen(dest) >= size)
		return (size + ft_strlen(src));
	j = 0;
	while (1)
	{
		dest[i] = src[j];
		if (src[j] == '\0')
			break ;
		else if (i == size - 1)
		{
			dest[i] = '\0';
			break ;
		}
		i++;
		j++;
	}
	return (out + ft_strlen(src));
}
