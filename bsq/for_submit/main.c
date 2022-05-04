#include "ajtcsheader.h"

void	init_info(t_info *p_info)
{
	p_info->empty = '\0';
	p_info->fill = '\0';
	p_info->obs = '\0';
	p_info->len = 0;
	p_info->tall = 0;
}

void	free_map(char **map, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->tall)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_error_msg(void)
{
	write(2, "map error\n", 10);
	exit(0);
}

void	find_and_print(char *filename, t_info *info)
{
	char	**map;

	map = map_malloc(filename, info);
	if (map == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	finder_main(map, info);
	free_map(map, info);
}

int	main(int argc, char *argv[])
{
	int		argv_idx;
	t_info	info;

	init_info(&info);
	if (argc == 1)
	{
		if (make_input_file() == 0)
			print_error_msg();
		if (check_input("AJTCS", &info) == 0)
			print_error_msg();
		find_and_print("AJTCS", &info);
	}
	argv_idx = 1;
	while (argv_idx < argc)
	{
		init_info(&info);
		if (check_input(argv[argv_idx], &info) == 0)
			write(2, "map error\n", 10);
		else
			find_and_print(argv[argv_idx], &info);
		if (argv_idx < argc - 1)
			write(1, "\n", 1);
		argv_idx++;
	}
	return (0);
}
