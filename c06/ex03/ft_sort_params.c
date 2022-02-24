/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:58:00 by siykim            #+#    #+#             */
/*   Updated: 2022/02/15 14:36:09 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{	
		if (s1[i] - s2[i] != 0)
			return (s1[i] - s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

void	sort(char *argv[])
{
	 int	i;
	 int	j;
	char	*temp;

	while (1)
	{
		i = 1;
		j = 0;
		while (argv[i + 1] != 0)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				temp = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = temp;
				j++;
			}
			i++;
		}
		if (j == 0)
			break ;
	}	
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	sort(argv);
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
