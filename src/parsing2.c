/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:41:01 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:42:11 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_good_symbol(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	return (0);
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

	y = 0;
	init_tab_count(tab_count, game);
	while (cpy_map[y])
	{
		x = 0;
		while (cpy_map[y][x])
		{
			if (cpy_map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			x++;
		}
		y++;
	}
	flood_fill(game->player_y, game->player_x, tab_count, cpy_map);
	return (free_map(cpy_map), tab_count[0] == 0 && tab_count[1] == 1);
}
