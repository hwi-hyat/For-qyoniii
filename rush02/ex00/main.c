/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaejeon <chaejeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:19:07 by siykim            #+#    #+#             */
/*   Updated: 2022/02/20 21:36:47 by chaejeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

void	print(t_dict *p, int keys)
{
	int	i;

	i = 0;
	while (i < keys + 1)
	{
		free(p[i].key);
		free(p[i].value);
		i++;
	}
	free(p);
}

int	argument_checker(int argc)
{
	if (argc < 1 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char	*dict_orig;
	t_dict	*p;
	int		keys;

	keys = 0;
	dict_orig = dict_director(argc, argv, &keys);
	p = (t_dict *)malloc(sizeof(t_dict) * (keys + 1));
	if (p == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (splitter(dict_orig, p) == 0 || dict_orig == 0)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	free(dict_orig);
	check_zero(argv[argc - 1], p);
	print(p, keys);
	return (0);
}
