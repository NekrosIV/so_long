/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasingh <kasingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:51:17 by kasingh           #+#    #+#             */
/*   Updated: 2024/03/08 18:23:37 by kasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_game
{
	char			**map;
	int				rows;
	int				cols;
	int				coins;
	int				p_count;
	int				exit;
	int				e[2];
	int				monster;
	int				m[4][2];
	int				moves;
	char			direction;
	char			d_m;
	int				player_x;
	int				player_y;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr[26];
	long long		mv_start;
	long long		mv_monster;
	long long		mv_death;
}					t_game;

typedef struct s_position
{
	int				x;
	int				y;
}					t_position;

typedef struct s_node
{
	t_position		pos;
	struct s_node	*next;
}					t_node;

typedef struct s_bfs
{
	t_node			*queue;
	t_position		start;
	t_position		current;
	t_position		directions[4];
	t_position		next;
	int				exit;
}					t_bfs;

void				init_game(t_game *game);
void				init_tab_count(int tab_count[4], t_game *game);

void				get_map_rows(t_game *game, char *file);
void				rm_newline(t_game *game);
void				get_map(t_game *game, char *file);
void				get_pos_m(t_game *game);

void				free_map(char **map);
void				map_error(char **map, char *msg);

int					is_good_symbol(char c);
int					is_valid_map2(t_game *game);
char				**ft_cpy_2dtab(char **tab);
int					is_map_finishable(t_game *game, char **cpy_map);

void				enqueue(t_node **head, t_position pos);
t_position			dequeue(t_node **head);
bool				is_empty(const t_node *head);

bool				can_i_stop_here(char **map, int i, int y, int x);
void				do_bfs2(char **map, t_bfs *bfs, int i, int *collectibles);
bool				do_bfs(t_game *game, char **map, t_bfs *bfs,
						int collectibles);
bool				call_bfs(t_game *game, char **cpy_map);

void				flood_fill(int y, int x, int tab_count[3], char **cpy_map);
int					is_map_closed_by_1(t_game *game);
int					is_valid_map(t_game *game);
int					is_map_rectangle(t_game *game);
t_game				parse_map(t_game *game, char *file);

void				call_other_functions(t_game *game);

void				put_img(t_game *game, int x, int y, void *img);
void				init_tab_path(char tab[11]);
void				init_img(t_game *game);

int					mouse_close(t_game *game);
void				esc_close(t_game *game);
void				str_put(t_game *game);
int					key_hook(int keycode, t_game *game);
int					loop_hook(t_game *game);

void				do_move(t_game *game, int y, int x);
void				key_up(t_game *game);
void				key_down(t_game *game);
void				key_left(t_game *game);
void				key_right(t_game *game);

void				calculate_y_x(t_game *game);
int					good_sprite(t_game *game);
void				do_slower(t_game *game, int y, int x);
void				do_dead_anim(t_game *game);

char				calculate_direction_moster(void);
void				do_move_monster(t_game *game, int y, int x, int i);
void				monster_move2(t_game *game, int y, int x, int i);
int					monster_move(t_game *game);
void				*good_sprite_monster(t_game *game);
void				do_slower_monster(t_game *game);

long long			current_time_ms(void);
void				game_lose(t_game *game);
void				is_player_dead(t_game *game);

void				print_map(char **map);
void				map_render(t_game *game);

#endif