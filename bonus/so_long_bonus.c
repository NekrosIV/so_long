/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:04:59 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:14:59 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			if (game->map[y][x] == '0')
				put_img(game, x * 35, y * 35, game->img_ptr[0]);
			else if (game->map[y][x] == '1')
				put_img(game, x * 35, y * 35, game->img_ptr[1]);
			else if (game->map[y][x] == 'P')
				put_img(game, x * 35, y * 35, game->img_ptr[2]);
			else if (game->map[y][x] == 'C')
				put_img(game, x * 35, y * 35, game->img_ptr[3]);
			else if (game->map[y][x] == 'E')
				put_img(game, x * 35, y * 35, game->img_ptr[0]);
			else if (game->map[y][x] == 'M')
				put_img(game, x * 35, y * 35, game->img_ptr[9]);
			x++;
		}
		y++;
	}
}

int	monster_move(t_game *game)
{
	static int	i;
	int			y;
	int			x;
	int			good_mostr;

	y = game->m[i][0];
	x = game->m[i][1];
	game->d_m = calculate_direction_moster();
	if (game->map[y][x] == 'M')
		monster_move2(game, y, x, i);
	good_mostr = i;
	i++;
	if (i == game->monster)
		i = 0;
	return (good_mostr);
}

void	call_other_functions(t_game *game)
{
	srand(time(NULL));
	init_img(game);
	map_render(game);
	monster_move(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid number of arguments\n", 2), 0);
	game = parse_map(&game, av[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (free_map(game.map), 0);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.cols * 35, game.rows * 35
			+ 10, "SO_LONG");
	if (!game.win_ptr)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
		free_map(game.map);
		return (0);
	}
	call_other_functions(&game);
	mlx_loop_hook(game.mlx_ptr, loop_hook, &game);
	mlx_hook(game.win_ptr, 17, 0, mouse_close, &game);
	mlx_hook(game.win_ptr, 02, (1L << 0), key_hook, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
