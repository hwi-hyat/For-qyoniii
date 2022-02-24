/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:06 by siykim            #+#    #+#             */
/*   Updated: 2022/02/08 13:57:19 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (1)
	{									
		if (dest[i] == '\0')
			break ;
		i++;
	}
	while (1)
	{
		dest[i] = src[j];
		if (src[j] == '\0')
			break ;
		i++;
		j++;
	}
	return (dest);
}
