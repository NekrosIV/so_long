/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:55:36 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:03:50 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_good_symbol(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C' || c == 'M')
		return (1);
	return (0);
}

int	is_valid_map2(t_game *game)
{
	if (game->p_count != 1 || game->exit != 1 || game->coins < 1
		|| game->monster > 4)
		return (0);
	return (1);
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

int	is_map_finishable(t_game *game, char **cpy_map)
{
	int	tab_count[4];
	int	y;
	int	x;

	y = -1;
	init_tab_count(tab_count, game);
	while (cpy_map[++y])
	{
		x = -1;
		while (cpy_map[y][++x])
		{
			if (cpy_map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			if (cpy_map[y][x] == 'E')
			{
				game->e[0] = y;
				game->e[1] = x;
			}
		}
	}
	flood_fill(game->player_y, game->player_x, tab_count, cpy_map);
	return (free_map(cpy_map), tab_count[0] == 0 && tab_count[1] == 1);
}
