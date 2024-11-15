#ifndef COMMON_H
# define COMMON_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include "SDL2/SDL.h"
# include "structs.h"

//enemy00.c
int move_enemy_X(t_game *game);
void can_move_horizontalX(t_game *game);
int check_player_collisionX(t_game *game);
void change_directionX(t_game *game);
void update_enemy_positionX(t_game *game);

//enemy00.c
int move_enemy_Y(t_game *game);
void can_move_verticalY(t_game *game);
int check_player_collisionY(t_game *game);
void change_directionY(t_game *game);
void update_enemy_positionY(t_game *game);

//player00.c
int key_hook(int keycode, t_game *game);
int check_end_game(t_game *game, int new_x, int new_y);
int is_blocked(t_game *game, int new_x, int new_y);
void check_enemy_collisions(t_game *game, int new_x, int new_y);
void collect_coin(t_game *game, int new_x, int new_y);
void move_player_update(t_game *game, int new_x, int new_y);
void move_enemies(t_game *game);
int move_player(t_game *game, int new_x, int new_y);

//render_map.c
t_textures load_textures(void *mlx);
void render_cell(t_game *game, int x, int y);
void render_row(t_game *game, int y);
void render_map(t_game *game);
int load_game_assets(t_game *game);

//init.c
void	init_sdl(void);
void	init_game(t_game *game);
int		init_map(t_game *game, char *map_filename);

//main.c
void render_map(t_game *game);
char	*read_join(int fd, char	*saved);
char	*savedtilnl(char *saved, char c);
char	*savedaftnl(char *saved, char c);
char    **ft_read_map(int fd, int *max_y, int *max_x);
void	ft_copy_map(int max_y, int max_x, char **map);
int     ft_validate_map(char **map, int max_y, int max_x);
int     ft_check_walls(char **map, int max_y, int max_x);
void    ft_flood_fill(char **map, int y, int max_y, int x, int max_x, int *found_exit);
void ft_gold_drain(t_game *game);
void find_positions(t_game *game);
void count_coins(t_game *game);
int start_game(t_game *game);
void ft_title_screen(void);
void undo_v(t_game *game);

//get_next_line.c
char	*read_join(int fd, char	*saved);
char	*savedtilnl(char *saved, char c);
char	*savedaftnl(char *saved, char c);
char	*get_next_line(int fd);

#endif
