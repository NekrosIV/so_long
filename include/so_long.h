/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:15:45 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:49:26 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	int		rows;
	int		cols;
	int		coins;
	int		p_count;
	int		exit;
	int		moves;
	char	direction;
	int		player_x;
	int		player_y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr[10];
}			t_game;

void		get_map_rows(t_game *game, char *file);
void		rm_newline(t_game *game);
void		get_map(t_game *game, char *file);

int			is_good_symbol(char c);
char		**ft_cpy_2dtab(char **tab);
int			is_map_finishable(t_game *game, char **cpy_map);

void		free_map(char **map);
void		map_error(char **map, char *msg);

void		init_tab_count(int tab_count[4], t_game *game);
void		init_game(t_game *game);

void		flood_fill(int y, int x, int tab_count[3], char **cpy_map);
int			is_map_closed_by_1(t_game *game);
int			is_valid_map(t_game *game);
int			is_map_rectangle(t_game *game);
t_game		parse_map(t_game *game, char *file);

void		put_img(t_game *game, int x, int y, void *img);
void		init_tab_path(char tab[11]);
void		init_img(t_game *game);

int			mouse_close(t_game *game);
void		esc_close(t_game *game);
int			key_hook(int keycode, t_game *game);
int			loop_hook(t_game *game);

void		do_move(t_game *game, int y, int x);
void		key_up(t_game *game);
void		key_down(t_game *game);
void		key_left(t_game *game);
void		key_right(t_game *game);

#endif