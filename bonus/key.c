/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:50:57 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/09 11:17:47 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	do_move(t_game *game, int y, int x)
{
	game->moves++;
	printf("moves: %d\n", game->moves);
	game->map[y][x] = '0';
	if (game->direction == 'u')
		y = y - 1;
	else if (game->direction == 'd')
		y = y + 1;
	else if (game->direction == 'l')
		x = x - 1;
	else if (game->direction == 'r')
		x = x + 1;
	game->coins -= (game->map[y][x] == 'C');
	game->map[y][x] = 'P';
	game->player_y = y;
	game->player_x = x;
	game->mv_start = current_time_ms();
	if (y != game->e[0] && x != game->e[1])
		game->map[game->e[0]][game->e[1]] = 'E';
	if (game->coins == 0)
		put_img(game, game->e[1] * 35, game->e[0] * 35, game->img_ptr[4]);
}

void	key_up(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->direction != 'u')
	{
		if (game->map[y - 1][x] != '1')
		{
			game->direction = 'u';
			do_move(game, y, x);
		}
	}
}

void	key_down(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->direction != 'd')
	{
		if (game->map[y + 1][x] != '1')
		{
			game->direction = 'd';
			do_move(game, y, x);
		}
	}
}

void	key_left(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->direction != 'l')
	{
		if (game->map[y][x - 1] != '1')
		{
			game->direction = 'l';
			do_move(game, y, x);
		}
	}
}

void	key_right(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->direction != 'r')
	{
		if (game->map[y][x + 1] != '1')
		{
			game->direction = 'r';
			do_move(game, y, x);
		}
	}
}
