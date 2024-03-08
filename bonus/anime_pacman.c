/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anime_pacman.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:56:02 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 17:44:17 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	calculate_y_x(t_game *game)
{
	int	y;
	int	x;
	int	f;

	y = game->player_y;
	x = game->player_x;
	f = (game->coins == 0);
	if (game->direction == 'u' && game->map[y - 1][x] != '1')
		do_move(game, y, x);
	else if (game->direction == 'd' && game->map[y + 1][x] != '1')
		do_move(game, y, x);
	else if (game->direction == 'l' && game->map[y][x - 1] != '1')
		do_move(game, y, x);
	else if (game->direction == 'r' && game->map[y][x + 1] != '1')
		do_move(game, y, x);
	else
		game->direction = 0;
	if (game->direction == 0 && game->coins == 0 && game->player_x == game->e[1]
		&& game->player_y == game->e[0])
		game->exit = 0;
}

int	good_sprite(t_game *game)
{
	int	v;

	v = 5;
	if (game->direction == 'u' || game->direction == 'd')
	{
		if (game->player_y % 2 == 0)
			v = 2;
		else if (game->direction == 'u')
			v = 5;
		else if (game->direction == 'd')
			v = 7;
	}
	else if (game->direction == 'l' || game->direction == 'r')
	{
		if (game->player_x % 2 == 0)
			v = 2;
		else if (game->direction == 'l')
			v = 8;
		else if (game->direction == 'r')
			v = 6;
	}
	return (v);
}

void	do_slower(t_game *game, int y, int x)
{
	static int	i;
	long long	curent_time;
	int			v;

	curent_time = current_time_ms();
	if (curent_time - game->mv_start < 2)
		return ;
	v = good_sprite(game);
	if (game->direction == 'u')
		put_img(game, x, y + 35 - i, game->img_ptr[v]);
	else if (game->direction == 'd')
		put_img(game, x, y - 35 + i, game->img_ptr[v]);
	else if (game->direction == 'l')
		put_img(game, x + 35 - i, y, game->img_ptr[v]);
	else if (game->direction == 'r')
		put_img(game, x - 35 + i, y, game->img_ptr[v]);
	i++;
	game->mv_start = current_time_ms();
	if (i == 35)
	{
		i = 0;
		is_player_dead(game);
		calculate_y_x(game);
	}
}

void	do_dead_anim(t_game *game)
{
	static int	i;
	long long	curent_time;
	int			y;
	int			x;
	int			v;

	y = game->player_y * 35;
	x = game->player_x * 35;
	v = 13 + i;
	curent_time = current_time_ms();
	if (curent_time - game->mv_death < 75)
		return ;
	put_img(game, x, y, game->img_ptr[0]);
	if (v <= 24)
		put_img(game, x, y, game->img_ptr[v]);
	i++;
	game->mv_death = current_time_ms();
	if (i == 19)
	{
		i = 0;
		game_lose(game);
	}
}
