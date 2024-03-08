/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:45:03 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:45:09 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	game->mlx_ptr = 0;
	game->win_ptr = 0;
	game->direction = 0;
	i = 0;
	while (i < 10)
	{
		game->img_ptr[i] = 0;
		i++;
	}
}
