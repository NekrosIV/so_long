/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:29:10 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:30:55 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void	init_tab_path(char tab[11])
{
	tab[0] = 'i';
	tab[1] = 'm';
	tab[2] = 'g';
	tab[3] = '/';
	tab[4] = '0';
	tab[6] = '.';
	tab[7] = 'x';
	tab[8] = 'p';
	tab[9] = 'm';
	tab[10] = '\0';
}

void	init_img(t_game *game)
{
	int		width;
	int		height;
	int		i;
	char	tab[11];

	i = 0;
	init_tab_path(tab);
	while (i < 9)
	{
		if (i < 10)
			tab[5] = '0' + i;
		else
		{
			tab[4] = i / 10 + '0';
			tab[5] = i % 10 + '0';
		}
		game->img_ptr[i] = mlx_xpm_file_to_image(game->mlx_ptr, tab, &width,
				&height);
		if (!game->img_ptr[i])
		{
			ft_putstr_fd("Error\nImage failed to load\n", 2);
			esc_close(game);
		}
		i++;
	}
}
