/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:23:48 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 17:46:31 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long long	current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	game_lose(t_game *game)
{
	ft_printf("You lost in %d moves\n", game->moves);
	esc_close(game);
}

void	is_player_dead(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		if (game->player_x == game->m[i][1] && game->player_y == game->m[i][0])
		{
			game->direction = 0;
			game->d_m = 0;
			game->map[game->player_y][game->player_x] = '0';
			while (j < 4)
			{
				if (game->m[j][0] != 0 && game->m[j][1] != 0)
					game->map[game->m[j][0]][game->m[j][1]] = '0';
				j++;
			}
			map_render(game);
			game->mv_death = current_time_ms();
		}
		i++;
	}
}
