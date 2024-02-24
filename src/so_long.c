/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:00:36 by kasingh           #+#    #+#             */
/*   Updated: 2024/02/24 11:48:40 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	map_error(char **map, char *msg)
{
	ft_putstr_fd(msg, 2);
	free_map(map);
	exit(1);
}

int	is_map_closed_by_1(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (i == 0 || i == map->rows - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == map->cols - 1)
			{
				if (map->map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_good_symbol(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
}

int	is_valid_map(t_map *map)
{
	int			i;
	int			j;
	static int	tab[3];

	i = 0;
	if (!is_map_closed_by_1(map))
		map_error(map->map, "Error\nMap is not closed by 1\n");
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!is_good_symbol(map->map[i][j]))
				map_error(map->map, "Error\nInvalid symbol in map\n");
			tab[0] += (map->map[i][j] == 'P');
			tab[1] += (map->map[i][j] == 'E');
			tab[2] += (map->map[i][j] == 'C');
			j++;
		}
		i++;
	}
	if (tab[0] != 1 || tab[1] != 1 || tab[2] < 1)
		return (0);
	return (1);
}

int	is_map_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if ((int)ft_strlen(map->map[i]) != map->cols)
			return (0);
		i++;
	}
	return (1);
}

void	flood_fill(int y, int x, int tab_count[3], char **cpy_map)
{
	if (y < 0 || y >= tab_count[2] || x < 0 || x >= tab_count[3]
		|| cpy_map[y][x] == '1' || cpy_map[y][x] == 'V')
		return ;
	tab_count[0] -= (cpy_map[y][x] == 'C');
	if (cpy_map[y][x] == 'E')
	{
		tab_count[1]++;
		cpy_map[y][x] = 'V';
		return ;
	}
	cpy_map[y][x] = 'V';
	flood_fill(y + 1, x, tab_count, cpy_map);
	flood_fill(y - 1, x, tab_count, cpy_map);
	flood_fill(y, x + 1, tab_count, cpy_map);
	flood_fill(y, x - 1, tab_count, cpy_map);
}

void	init_tab_count(int tab_count[4], int rows, int cols)
{
	tab_count[0] = 0;
	tab_count[1] = 0;
	tab_count[2] = rows;
	tab_count[3] = cols;
}

int	is_map_finishable(t_map *map, char **cpy_map)
{
	int			tab_count[4];
	int			y;
	int			x;
	static int	p_start[2];

	y = 0;
	init_tab_count(tab_count, map->rows, map->cols);
	while (cpy_map[y])
	{
		x = 0;
		while (cpy_map[y][x])
		{
			tab_count[0] += (cpy_map[y][x] == 'C');
			if (cpy_map[y][x] == 'P')
			{
				p_start[0] = y;
				p_start[1] = x;
			}
			x++;
		}
		y++;
	}
	flood_fill(p_start[0], p_start[1], tab_count, cpy_map);
	return (free_map(cpy_map), tab_count[0] == 0 && tab_count[1] == 1);
}

void	get_map_rows(t_map *map, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	map->rows = i;
}

void	rm_newline(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
			map->map[i][ft_strlen(map->map[i]) - 1] = '\0';
		i++;
	}
}

void	get_map(t_map *map, char *file)
{
	int	fd;
	int	i;

	i = 0;
	map->map = malloc((map->rows + 1) * sizeof(char *));
	if (!map->map)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file);
		exit(1);
	}
	while (1)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i++])
			break ;
	}
	rm_newline(map);
	close(fd);
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		ft_printf("%s\n", map->map[i]);
		i++;
	}
}

char	**ft_cpy_2dtab(char **tab)
{
	char	**cpy;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	cpy = malloc((i + 1) * sizeof(char *));
	if (!cpy)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		exit(1);
	}
	i = 0;
	while (tab[i])
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

t_map	parse_map(t_map *map, char *file)
{
	char	**cpy_map;

	if (ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		exit(1);
	}
	get_map_rows(map, file);
	get_map(map, file);
	ft_print_map(map);
	map->cols = ft_strlen(map->map[0]);
	if ((map->rows < 3 || map->cols < 5) && ft_strlen(map->map[map->rows - 1]) < 5)
		map_error(map->map, "Error\nMap is too small\n");
	if (!is_map_rectangle(map))
		map_error(map->map, "Error\nMap is not a rectangle\n");
	if (!is_valid_map(map))
		map_error(map->map, "Error\nMap is not valid\n");
	cpy_map = ft_cpy_2dtab(map->map);
	if (!is_map_finishable(map, cpy_map))
		map_error(map->map, "Error\nMap is not finishable\n");
	return (*map);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	map = parse_map(&map, av[1]);
	ft_printf("Map is valid\n");
	free_map(map.map);
	return (0);
}
