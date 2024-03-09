/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:32:06 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/09 11:54:29 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_move(t_game *game, int y, int x)
{
	game->moves++;
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
	game->exit -= (game->map[y][x] == 'E');
	game->map[y][x] = 'P';
	game->player_y = y;
	game->player_x = x;
}

void	key_up(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->map[y - 1][x] == '0' || game->map[y - 1][x] == 'C')
	{
		game->direction = 'u';
		do_move(game, y, x);
	}
	else if (game->map[y - 1][x] == 'E' && game->coins == 0)
	{
		game->direction = 'u';
		do_move(game, y, x);
	}
}

void	key_down(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->map[y + 1][x] == '0' || game->map[y + 1][x] == 'C')
	{
		game->direction = 'd';
		do_move(game, y, x);
	}
	else if (game->map[y + 1][x] == 'E' && game->coins == 0)
	{
		game->direction = 'd';
		do_move(game, y, x);
	}
}

void	key_left(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->map[y][x - 1] == '0' || game->map[y][x - 1] == 'C')
	{
		game->direction = 'l';
		do_move(game, y, x);
	}
	else if (game->map[y][x - 1] == 'E' && game->coins == 0)
	{
		game->direction = 'l';
		do_move(game, y, x);
	}
}

void	key_right(t_game *game)
{
	int	y;
	int	x;

	y = game->player_y;
	x = game->player_x;
	if (game->map[y][x + 1] == '0' || game->map[y][x + 1] == 'C')
	{
		game->direction = 'r';
		do_move(game, y, x);
	}
	else if (game->map[y][x + 1] == 'E' && game->coins == 0)
	{
		game->direction = 'r';
		do_move(game, y, x);
	}
}
