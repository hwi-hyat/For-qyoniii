/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:59 by siykim            #+#    #+#             */
/*   Updated: 2022/02/08 13:59:13 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
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
	while (j < nb)
	{
		dest[i] = src[j];
		if (src[j] == '\0')
			break ;
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
