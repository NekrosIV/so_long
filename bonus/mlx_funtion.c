/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funtion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:53:51 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/10 11:32:44 by kasingh          ###   ########.fr       */
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

void	str_put(t_game *game)
{
	char	*str;
	char	*str2;
	int		i;

	str = ft_itoa(game->moves);
	if (!str)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		esc_close(game);
	}
	str2 = ft_strjoin("Moves: ", str);
	if (!str)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		esc_close(game);
	}
	i = -1;
	while (++i < game->cols - 1)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr[0],
			i * 35, game->rows * 35);
	mlx_string_put(game->mlx_ptr, game->win_ptr, game->cols / 2 * 35, game->rows
		* 35 + 10, 0xFFFFFF, str2);
	free(str);
	free(str2);
}

int	key_hook(int keycode, t_game *game)
{
	static int	i;

	if (keycode == XK_Escape)
		esc_close(game);
	else if (game->direction != 0)
		return (0);
	else if (keycode == XK_e || keycode == XK_n || keycode == XK_h
		|| keycode == XK_i)
		chose_game_mode(game, keycode);
	else if (keycode == XK_Up && game->mv_death == 0)
		key_up(game);
	else if (keycode == XK_Down && game->mv_death == 0)
		key_down(game);
	else if (keycode == XK_Left && game->mv_death == 0)
		key_left(game);
	else if (keycode == XK_Right && game->mv_death == 0)
		key_right(game);
	if (i != game->moves || i == 0)
	{
		str_put(game);
		i = game->moves;
	}
	return (0);
}

int	loop_hook(t_game *game)
{
	if (game->moves != 0 && game->mv_death == 0 && game->monster != 0)
		do_slower_monster(game);
	if (game->direction != 0 && game->mv_death == 0)
		do_slower(game, game->player_y * 35, game->player_x * 35);
	if (game->mv_death != 0)
		do_dead_anim(game);
	if (game->exit == 0)
	{
		ft_printf("you won in %d moves\n", game->moves);
		esc_close(game);
	}
	return (0);
}
