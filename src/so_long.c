/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:00:36 by kasingh           #+#    #+#             */
/*   Updated: 2024/02/20 16:47:25 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_2tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
void	map_error(t_map *map)
{
	ft_printf("Error\nInvalid map\n");
	free_map(map);
	exit(1);
}

int	is_valid_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0'
				&& map->map[i][j] != 'P' && map->map[i][j] != 'E'
				&& map->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_rectangle(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != map->cols)
			return (0);
		i++;
	}
	return (1);
}
int	is_map_finishable(t_map *map)
{
	
}

void	get_map(t_map *map, char *file)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nInvalid file\n");
		exit(1);
	}
	while (1)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
			break ;
		i++;
	}
	close(fd);
}

int	parse_map(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	get_map(map, file);
	map->rows = ft_2tablen(map->map);
	map->cols = ft_strlen(map->map[0]);
	if (map->rows < 3 || map->cols < 3)
		map_error(map);
	if (!is_map_rectangle(map))
		map_error(map);
	if (!is_valid_map(map))
		map_error(map);
	if (!is_map_finishable(map))
		map_error(map);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_printf("Error\nInvalid number of arguments\n");
	parse_map(av[1]);
}
