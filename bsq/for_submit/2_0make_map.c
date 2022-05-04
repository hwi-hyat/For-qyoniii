
#include "ajtcsheader.h"

void	first_line_skip(int fd)
{
	char	temp;

	temp = 0;
	while (temp != '\n')
		read(fd, &temp, 1);
}

void	line_copy_map(int fd, char *map_line)
{
	int		i;
	char	temp;

	i = 0;
	while (read(fd, &temp, 1))
	{
		if (temp == '\n')
			break ;
		map_line[i] = temp;
		i++;
	}
	map_line[i] = 0;
}

int	copy_map(char **map, char *filename, int tall)
{
	int		i;
	int		fd;

	fd = open(filename, O_RDWR);
	if (fd < 0)
		return (0);
	first_line_skip(fd);
	i = 0;
	while (i < tall)
	{
		line_copy_map(fd, map[i]);
		i++;
	}
	close(fd);
	return (1);
}

char	**malloc_err_free_map(char **map, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

char	**map_malloc(char *filename, t_info *info)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(sizeof(char *) * info->tall);
	if (map == NULL)
		return (0);
	while (i < info->tall)
	{
		map[i] = (char *)malloc(sizeof(char) * (info->len + 1));
		if (map[i] == NULL)
			return (malloc_err_free_map(map, i));
		i++;
	}
	if (copy_map(map, filename, info->tall) == 0)
		return (0);
	return (map);
}
