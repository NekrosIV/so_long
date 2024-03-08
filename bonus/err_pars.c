/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:07:13 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:07:20 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	map_error(char **map, char *msg)
{
	ft_putstr_fd(msg, 2);
	free_map(map);
	exit(1);
}
