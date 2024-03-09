/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:00:36 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/09 12:20:04 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*good_sprite(t_game *game)
{
	int	v;

	v = 5;
	if (game->direction == 'u')
		v = 5;
	else if (game->direction == 'd')
		v = 7;
	else if (game->direction == 'l')
		v = 8;
	else if (game->direction == 'r')
		v = 6;
	else
		v = 2;
	return (game->img_ptr[v]);
}

void	map_render(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				put_img(game, x * 35, y * 35, game->img_ptr[1]);
			else if (game->map[y][x] == 'P')
				put_img(game, x * 35, y * 35, good_sprite(game));
			else if (game->map[y][x] == '0')
				put_img(game, x * 35, y * 35, game->img_ptr[0]);
			else if (game->map[y][x] == 'C')
				put_img(game, x * 35, y * 35, game->img_ptr[3]);
			else if (game->map[y][x] == 'E' && game->coins != 0)
				put_img(game, x * 35, y * 35, game->img_ptr[1]);
			else if (game->map[y][x] == 'E' && game->coins <= 0)
				put_img(game, x * 35, y * 35, game->img_ptr[4]);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), 0);
	game = parse_map(&game, av[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (ft_putstr_fd("Error\nMLX failed to initialize\n", 2),
			free_map(game.map), 0);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.cols * 35, game.rows * 35
			+ 10, "SO_LONG");
	if (!game.win_ptr)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		free_map(game.map);
		return (ft_putstr_fd("Error\nWindow failed to create\n", 2), 0);
	}
	init_img(&game);
	mlx_loop_hook(game.mlx_ptr, loop_hook, &game);
	mlx_hook(game.win_ptr, 17, 0, mouse_close, &game);
	mlx_hook(game.win_ptr, 02, (1L << 0), key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
