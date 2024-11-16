
#ifndef STRUCTS_H
# define STRUCTS_H

# include "common.h"

typedef struct s_app {
	SDL_Window		*window;
	SDL_Renderer	*renderer;
} t_app;

typedef struct s_surfaces {
	SDL_Surface *wall;
	SDL_Surface *player;
	SDL_Surface *floor;
	SDL_Surface *exit;
	SDL_Surface *coin;
	SDL_Surface *enemy_y;
	SDL_Surface *enemy_x;
	SDL_Surface *enemy_v;
	SDL_Surface *enemy_h;
} t_surfaces;

typedef struct s_textures {
	SDL_Texture *wall;
	SDL_Texture *player;
	SDL_Texture *floor;
	SDL_Texture *exit;
	SDL_Texture *coin;
	SDL_Texture *enemy_y;
	SDL_Texture *enemy_x;
	SDL_Texture *enemy_v;
	SDL_Texture *enemy_h;
} t_textures;

typedef struct s_score {
	int highscore;
	int kill_highscore;
	int coins_highscore;
} t_score;

typedef struct s_player {
	int gold_rush;
	int step_counter;
    int player_x;
    int player_y;
} t_player;

typedef struct s_enemy {
	int enemy_y_y;
	int enemy_y_x;
	int enemy_x_y;
	int enemy_x_x;
	int enemy_v_y;
	int enemy_v_x;
	int enemy_h_y;
	int enemy_h_x;
	int enemy_y_dead;
	int enemy_x_dead;
	int enemy_h_dead;
	int enemy_v_dead;
} t_enemy;

typedef struct s_game {
    void *win;
    char **map;
	int	max_y;
	int max_x;
	int found_coins;
	int count_coins;
	int direction_y;
	int direction_x;
	int direction_v;
	int direction_h;
    t_textures textures;
} t_game;

#endif
