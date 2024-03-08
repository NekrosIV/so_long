/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:37:57 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:40:01 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	is_valid_map(t_game *game)
{
	int	i;
	int	j;

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
			game->p_count += (game->map[i][j] == 'P');
			game->exit += (game->map[i][j] == 'E');
			game->coins += (game->map[i][j] == 'C');
			j++;
		}
		i++;
	}
	if (game->p_count != 1 || game->exit != 1 || game->coins < 1)
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

t_game	parse_map(t_game *game, char *file)
{
	char	**cpy_map;

	if (ft_strncmp(&file[ft_strlen(file) - 4], ".ber", 4))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		exit(1);
	}
	init_game(game);
	get_map_rows(game, file);
	get_map(game, file);
	game->cols = ft_strlen(game->map[0]);
	if ((game->rows < 3 || game->cols < 5) && ft_strlen(game->map[game->rows
			- 1]) < 5)
		map_error(game->map, "Error\nMap is too small\n");
	if (game->rows * 35 > 1080 || game->cols * 35 > 1920)
		map_error(game->map, "Error\nMap is too big\n");
	if (!is_map_rectangle(game))
		map_error(game->map, "Error\nMap is not a rectangle\n");
	if (!is_valid_map(game))
		map_error(game->map, "Error\nMap is not valid\n");
	cpy_map = ft_cpy_2dtab(game->map);
	if (!is_map_finishable(game, cpy_map))
		map_error(game->map, "Error\nMap is not finishable\n");
	return (*game);
}
