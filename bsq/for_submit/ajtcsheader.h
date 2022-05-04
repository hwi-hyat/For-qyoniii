
#ifndef AJTCSHEADER_H
# define AJTCSHEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_start
{
	int	x;
	int	y;
}t_start;

typedef struct s_max
{
	int	max_x;
	int	max_y;
	int	max_size;
}t_max;

typedef struct s_info
{
	char	empty;
	char	obs;
	char	fill;
	int		len;
	int		tall;
}t_info;

int		ft_strlen(char *str);
int		fill_obs_empty_ok(char *str, t_info *p_info, int len);
int		check_condition(char *str, t_info *p_info);
int		check_tall_line(char *str, t_info *p_info);
int		check_str(char *str, int line_count, t_info *p_info);
int		check_map(int fd, t_info *p_info, char *temp_line);
int		check_input(char *filename, t_info *p_info);
int		make_input_file(void);
char	**map_malloc(char *filename, t_info *info);
void	finder_main(char **map, t_info *map_info);
int		obs_chk(char c, t_info *map_info);
void	is_it_max(t_start co, int size, t_max *max);
int		val_map_acc(t_start co, int size, t_info *map_info);
void	printer(char **map, t_info *map_info);

#endif
