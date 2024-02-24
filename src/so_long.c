/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:00:36 by kasingh           #+#    #+#             */
/*   Updated: 2024/02/24 14:56:30 by kasingh          ###   ########.fr       */
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

int	is_map_closed_by_1(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (i == 0 || i == game->rows - 1)
			{
				if (game->map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == game->cols - 1)
			{
				if (game->map[i][j] != '1')
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

int	is_valid_map(t_game *game)
{
	int			i;
	int			j;
	static int	tab[3];

	i = 0;
	if (!is_map_closed_by_1(game))
		map_error(game->map, "Error\nMap is not closed by 1\n");
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_good_symbol(game->map[i][j]))
				map_error(game->map, "Error\nInvalid symbol in map\n");
			tab[0] += (game->map[i][j] == 'P');
			tab[1] += (game->map[i][j] == 'E');
			tab[2] += (game->map[i][j] == 'C');
			j++;
		}
		i++;
	}
	if (tab[0] != 1 || tab[1] != 1 || tab[2] < 1)
		return (0);
	return (1);
}

int	is_map_rectangle(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->cols)
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

int	is_map_finishable(t_game *game, char **cpy_map)
{
	int			tab_count[4];
	int			y;
	int			x;
	static int	p_start[2];

	y = 0;
	init_tab_count(tab_count, game->rows, game->cols);
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

void	get_map_rows(t_game *game, char *file)
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
	game->rows = i;
}

void	rm_newline(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
}

void	get_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	i = 0;
	game->map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
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
		game->map[i] = get_next_line(fd);
		if (!game->map[i++])
			break ;
	}
	rm_newline(game);
	close(fd);
}

void	ft_print_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\n", game->map[i]);
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

t_game	parse_map(t_game *game, char *file)
{
	char	**cpy_map;

	if (ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		exit(1);
	}
	get_map_rows(game, file);
	get_map(game, file);
	ft_print_game(game);
	game->cols = ft_strlen(game->map[0]);
	if ((game->rows < 3 || game->cols < 5) && ft_strlen(game->map[game->rows - 1]) < 5)
		map_error(game->map, "Error\nMap is too small\n");
	if (!is_map_rectangle(game))
		map_error(game->map, "Error\nMap is not a rectangle\n");
	if (!is_valid_map(game))
		map_error(game->map, "Error\nMap is not valid\n");
	cpy_map = ft_cpy_2dtab(game->map);
	if (!is_map_finishable(game, cpy_map))
		map_error(game->map, "Error\nMap is not finishable\n");
	return (*game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
	game = parse_map(&game, av[1]);
	ft_printf("Map is valid\n");
	free_map(game.map);
	return (0);
}
