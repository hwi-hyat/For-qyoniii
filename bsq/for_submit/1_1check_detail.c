#include "ajtcsheader.h"

int	fill_obs_empty_ok(char *str, t_info *info, int f_len)
{
	if (!(32 <= str[f_len - 1] && str[f_len - 1] <= 126))
		return (0);
	info->fill = str[f_len - 1];
	if (!(32 <= str[f_len - 2] && str[f_len - 2] <= 126))
		return (0);
	info->obs = str[f_len - 2];
	if (!(32 <= str[f_len - 3] && str[f_len - 3] <= 126))
		return (0);
	info->empty = str[f_len - 3];
	return (1);
}

int	check_condition(char *str, t_info *info)
{
	int	idx;
	int	f_len;

	f_len = ft_strlen(str);
	if (f_len < 4)
		return (0);
	if (fill_obs_empty_ok(str, info, f_len) == 0)
		return (0);
	if (info->fill == info->obs
		|| info->fill == info->empty
		|| info->obs == info->empty)
		return (0);
	idx = 0;
	while (idx < f_len - 3)
	{
		if (!('0' <= str[idx] && str[idx] <= '9'))
			return (0);
		info->tall = (info->tall * 10) + (str[idx] - '0');
		idx++;
	}
	if (info->tall == 0)
		return (0);
	return (1);
}

int	check_tall_line(char *str, t_info *info)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!((str[idx] == info->empty) || (str[idx] == info->obs)))
			return (0);
		idx++;
	}
	return (idx);
}
