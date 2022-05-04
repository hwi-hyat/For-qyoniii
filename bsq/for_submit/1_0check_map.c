#include "ajtcsheader.h"

int	check_str(char *str, int line_count, t_info *info)
{
	if (line_count == 0)
	{
		if (check_condition(str, info) == 0)
			return (0);
	}
	else if (line_count == 1)
	{
		info->len = check_tall_line(str, info);
		if (info->len == 0)
			return (0);
	}
	else
	{
		if (check_tall_line(str, info) != info->len)
			return (0);
	}
	return (1);
}

int	check_map(int fd, t_info *info, char *temp_line)
{
	char	buf;
	int		idx;
	int		count;

	count = 0;
	while (read(fd, &buf, 1) > 0)
	{
		idx = 0;
		while (buf != '\n')
		{
			temp_line[idx] = buf;
			idx++;
			if (read(fd, &buf, 1) <= 0)
				return (0);
		}
		temp_line[idx] = '\0';
		if (check_str(temp_line, count, info) == 0)
			return (0);
		count++;
	}
	if ((count - 1) != info->tall)
		return (0);
	return (1);
}

int	len_check(char *filename)
{
	int		fd;
	int		len;
	int		lenmax;
	char	buf;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
		{
			if (len > lenmax)
				lenmax = len;
			len = 0;
			continue ;
		}
		len++;
	}
	return (lenmax);
}

int	check_input(char *filename, t_info *info)
{
	int		fd;
	char	*temp_line;

	temp_line = (char *)malloc(sizeof(char) * (len_check(filename) + 1));
	if (temp_line == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1 || check_map(fd, info, temp_line) == 0)
	{
		free(temp_line);
		return (0);
	}
	close(fd);
	free(temp_line);
	return (1);
}
