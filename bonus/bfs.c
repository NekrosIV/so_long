/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:13:09 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/09 18:13:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	can_i_stop_here(char **map, int i, int y, int x)
{
	if (i == 0 && map[y - 1][x] == '1')
		return (true);
	if (i == 1 && map[y + 1][x] == '1')
		return (true);
	if (i == 2 && map[y][x - 1] == '1')
		return (true);
	if (i == 3 && map[y][x + 1] == '1')
		return (true);
	return (false);
}

void	do_bfs2(char **map, t_bfs *bfs, int i, int *collectibles)
{
	bfs->next.x = bfs->current.x + bfs->directions[i].x;
	bfs->next.y = bfs->current.y + bfs->directions[i].y;
	while (map[bfs->next.y][bfs->next.x] != '1')
	{
		if (map[bfs->next.y][bfs->next.x] == 'C')
		{
			(*collectibles)--;
			map[bfs->next.y][bfs->next.x] = '0';
		}
		if (map[bfs->next.y][bfs->next.x] == 'E' && can_i_stop_here(map, i,
				bfs->next.y, bfs->next.x))
		{
			bfs->exit++;
			map[bfs->next.y][bfs->next.x] = '0';
		}
		bfs->next.x += bfs->directions[i].x;
		bfs->next.y += bfs->directions[i].y;
	}
	bfs->next.x -= bfs->directions[i].x;
	bfs->next.y -= bfs->directions[i].y;
	if (map[bfs->next.y][bfs->next.x] != 'V')
	{
		map[bfs->next.y][bfs->next.x] = 'V';
		enqueue(&bfs->queue, bfs->next);
	}
}

bool	do_bfs(char **map, t_bfs *bfs, int collectibles)
{
	int	i;

	bfs->exit = 0;
	bfs->queue = NULL;
	enqueue(&bfs->queue, bfs->start);
	map[bfs->start.y][bfs->start.x] = 'V';
	while (!is_empty(bfs->queue))
	{
		bfs->current = dequeue(&bfs->queue);
		if (bfs->exit != 0 && collectibles == 0)
		{
			while (!is_empty(bfs->queue))
				dequeue(&bfs->queue);
			return (true);
		}
		i = 0;
		while (i < 4)
		{
			do_bfs2(map, bfs, i, &collectibles);
			i++;
		}
	}
	return (false);
}

bool	call_bfs(t_game *game, char **cpy_map)
{
	t_bfs	bfs;
	bool	result;

	bfs.start.x = game->player_x;
	bfs.start.y = game->player_y;
	bfs.directions[0].x = 0;
	bfs.directions[0].y = -1;
	bfs.directions[1].x = 0;
	bfs.directions[1].y = 1;
	bfs.directions[2].x = -1;
	bfs.directions[2].y = 0;
	bfs.directions[3].x = 1;
	bfs.directions[3].y = 0;
	cpy_map = ft_cpy_2dtab(game->map);
	result = do_bfs(cpy_map, &bfs, game->coins);
	free_map(cpy_map);
	return (result);
}
