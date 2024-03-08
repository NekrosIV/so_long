/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:33:41 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:34:45 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	mouse_close(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	while (game->img_ptr[i] != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptr[i]);
		i++;
	}
	mlx_destroy_display(game->mlx_ptr);
	free_map(game->map);
	free(game->mlx_ptr);
	exit(0);
}

void	esc_close(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	while (game->img_ptr[i] != NULL)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptr[i]);
		i++;
	}
	mlx_destroy_display(game->mlx_ptr);
	free_map(game->map);
	free(game->mlx_ptr);
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	static int	i;

	if (keycode == XK_Escape)
		esc_close(game);
	else if (keycode == XK_Up)
		key_up(game);
	else if (keycode == XK_Down)
		key_down(game);
	else if (keycode == XK_Left)
		key_left(game);
	else if (keycode == XK_Right)
		key_right(game);
	if (i != game->moves || i == 0)
	{
		ft_printf("Moves: %d\n", game->moves);
		i = game->moves;
	}
	return (0);
}

int	loop_hook(t_game *game)
{
	map_render(game);
	if (game->exit == 0)
	{
		ft_printf("you won in %d moves\n", game->moves);
		esc_close(game);
	}
	return (0);
}
