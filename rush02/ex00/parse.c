/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:19:32 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 20:19:34 by siykim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

char	*parse_duplicate(int *keys, char *dict_dir, char *dict)
{
	int		fd;
	int		i;
	char	temp;

	i = 0;
	fd = open(dict_dir, O_RDWR);
	while (read(fd, &temp, 1) >= 1)
	{
		if (temp == '\n')
			(*keys)++;
		dict[i] = temp;
		i++;
	}
	close(fd);
	return (dict);
}

char	*parse_length_check(int *keys, char *dict_dir)
{
	char	*dict;
	char	temp;
	int		fd;
	int		i;

	fd = open(dict_dir, O_RDWR);
	if (fd < 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	i = 0;
	while (read(fd, &temp, 1) >= 1)
		i++;
	dict = (char *)malloc(sizeof(char) * i);
	if (dict == NULL)
		return (0);
	i = 0;
	close(fd);
	return (parse_duplicate(keys, dict_dir, dict));
}

char	*dict_director(int argc, char *argv[], int *keys)
{
	if (argc == 2)
		return (parse_length_check(keys, "numbers.dict"));
	else if (argc == 3)
		return (parse_length_check(keys, argv[1]));
	return (0);
}
