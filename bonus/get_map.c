/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:01:27 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:02:06 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_map_rows(t_game *game, char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file);
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
	}
	close(fd);
	game->rows = i;
}

void	rm_newline(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
}

void	get_map(t_game *game, char *file)
{
	int	fd;
	int	i;

	i = 0;
	game->map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
	{
		ft_putstr_fd("Error\nMalloc failed\n", 2);
		exit(1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 2);
		perror(file);
		exit(1);
	}
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i++])
			break ;
	}
	rm_newline(game);
	close(fd);
}

void	get_pos_m(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < 4)
	{
		game->m[i][0] = 0;
		game->m[i][1] = 0;
	}
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'M')
			{
				game->m[k][0] = i;
				game->m[k][1] = j;
				k++;
			}
		}
	}
}
