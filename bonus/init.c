/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:48:12 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/10 11:44:25 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chose_game_mode(t_game *game, int keycode)
{
	if (keycode == XK_e)
		game->game_mode = 'e';
	else if (keycode == XK_n)
		game->game_mode = 'n';
	else if (keycode == XK_h)
		game->game_mode = 'h';
	else if (keycode == XK_i)
		game->game_mode = 'i';
}

void	init_tab_count(int tab_count[4], t_game *game)
{
	tab_count[0] = game->coins;
	tab_count[1] = 0;
	tab_count[2] = game->rows;
	tab_count[3] = game->cols;
}

void	init_game(t_game *game)
{
	int	i;

	game->map = 0;
	game->rows = 0;
	game->cols = 0;
	game->coins = 0;
	game->exit = 0;
	game->p_count = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->e[0] = 0;
	game->e[1] = 0;
	game->monster = 0;
	game->d_m = 0;
	game->game_mode = 'e';
	game->direction = 0;
	game->mlx_ptr = 0;
	game->win_ptr = 0;
	game->mv_start = 0;
	game->mv_monster = 0;
	game->mv_death = 0;
	i = -1;
	while (++i < 27)
		game->img_ptr[i] = 0;
}
