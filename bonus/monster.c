/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:11:05 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/10 11:56:26 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	random_direction_moster(void)
{
	int	random;

	random = rand() % 4;
	if (random == 0)
		return ('u');
	else if (random == 1)
		return ('d');
	else if (random == 2)
		return ('l');
	else
		return ('r');
}

void	do_move_monster(t_game *game, int y, int x, int i)
{
	game->map[y][x] = '0';
	if (game->d_m == 'u')
		y = y - 1;
	else if (game->d_m == 'd')
		y = y + 1;
	else if (game->d_m == 'l')
		x = x - 1;
	else if (game->d_m == 'r')
		x = x + 1;
	game->m[i][0] = y;
	game->m[i][1] = x;
	game->map[y][x] = 'M';
	game->mv_monster = current_time_ms();
}

void	monster_move2(t_game *game, int y, int x, int i)
{
	if (game->d_m == 'u' && (game->map[y - 1][x] == '0' || game->map[y
			- 1][x] == 'P'))
		do_move_monster(game, y, x, i);
	else if (game->d_m == 'd' && (game->map[y + 1][x] == '0' || game->map[y
			+ 1][x] == 'P'))
		do_move_monster(game, y, x, i);
	else if (game->d_m == 'l' && (game->map[y][x - 1] == '0' || game->map[y][x
		- 1] == 'P'))
		do_move_monster(game, y, x, i);
	else if (game->d_m == 'r' && (game->map[y][x + 1] == '0' || game->map[y][x
		+ 1] == 'P'))
		do_move_monster(game, y, x, i);
	else
		game->d_m = 0;
}

void	*good_sprite_monster(t_game *game)
{
	int	v;

	v = 5;
	if (game->d_m == 'u')
		v = 9;
	else if (game->d_m == 'r')
		v = 10;
	else if (game->d_m == 'd')
		v = 11;
	else if (game->d_m == 'l')
		v = 12;
	return (game->img_ptr[v]);
}

void	do_slower_monster(t_game *game)
{
	static int	tab[4];
	long long	curent_time;

	tab[2] = game->m[tab[1]][0] * 35;
	tab[3] = game->m[tab[1]][1] * 35;
	curent_time = current_time_ms();
	if (curent_time - game->mv_monster < 3)
		return ;
	tab[0]++;
	if (game->d_m == 'u')
		put_img(game, tab[3], tab[2] + 35 - tab[0], good_sprite_monster(game));
	else if (game->d_m == 'd')
		put_img(game, tab[3], tab[2] - 35 + tab[0], good_sprite_monster(game));
	else if (game->d_m == 'l')
		put_img(game, tab[3] + 35 - tab[0], tab[2], good_sprite_monster(game));
	else if (game->d_m == 'r')
		put_img(game, tab[3] - 35 + tab[0], tab[2], good_sprite_monster(game));
	game->mv_monster = current_time_ms();
	if (tab[0] == 35)
	{
		tab[0] = 0;
		is_player_dead(game);
		game->d_m = 0;
		tab[1] = monster_move(game);
	}
}
