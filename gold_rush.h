#ifndef GOLD_RUSH_H
# define GOLD_RUSH_H


# endif

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
#include <SDL2/SDL.h>

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

typedef struct s_game {
    SDL_Window *win;             // Fenster
    SDL_Renderer *renderer;      // Renderer zum Zeichnen
    char **map;                  // Spielkarte
    int max_y;                   // Maximale Y-Größe der Karte
    int max_x;                   // Maximale X-Größe der Karte
    int player_x;                // Spieler X-Position
    int player_y;                // Spieler Y-Position
    int enemy_v_y;               // Gegner (vertikal) Y-Position
    int enemy_v_x;               // Gegner (vertikal) X-Position
    int enemy_h_y;               // Gegner (horizontal) Y-Position
    int enemy_h_x;               // Gegner (horizontal) X-Position
    int enemy_h_dead;            // Status für horizontalen Gegner (tot oder lebendig)
    int enemy_v_dead;            // Status für vertikalen Gegner (tot oder lebendig)
    int found_coins;             // Gefundene Münzen
    int count_coins;             // Zähler für Münzen
    int direction_v;             // Richtung des vertikalen Gegners
    int direction_h;             // Richtung des horizontalen Gegners
    int step_counter;            // Schrittzähler
    int highscore;               // Höchstpunktzahl
    int kill_highscore;          // Höchstpunktzahl für Kills
    int coins_highscore;         // Höchstpunktzahl für Münzen
    int gold_rush;               // Goldrausch-Zustand
    t_textures textures;         // Texturen für die Spielobjekte
} t_game;

//gold_rush.c
void		ft_gold_drain(t_game *game);
void		ft_title_screen(void);

//position.c
void 		find_positions(t_game *game);
void 		count_coins(t_game *game);
void 		find_positions_X(t_game *game);
void 		find_positions_Y(t_game *game);

//player00.c
int			check_end_game(t_game *game, int new_x, int new_y);
int			is_blocked(t_game *game, int new_x, int new_y);
void		check_enemy_collisions(t_game *game, int new_x, int new_y);
void		collect_coin(t_game *game, int new_x, int new_y);

//player01.c
int			key_hook(int keycode, t_game *game);
void		move_player_update(t_game *game, int new_x, int new_y);
void		move_enemies(t_game *game);
int			move_player(t_game *game, int new_x, int new_y);

//enemy00.c
int			move_enemy_X(t_game *game);
void		can_move_horizontalX(t_game *game);
int			check_player_collisionX(t_game *game);
void		change_directionX(t_game *game);
void 		update_enemy_positionX(t_game *game);

//enemy00.c
int			move_enemy_Y(t_game *game);
void 		can_move_verticalY(t_game *game);
int			check_player_collisionY(t_game *game);
void		change_directionY(t_game *game);
void		update_enemy_positionY(t_game *game);

//main.c
void		init_game(t_game *game);
int			init_window_and_map(t_game *game, char *map_filename);
int			create_window(t_game *game);
int			start_game(t_game *game);


#endif
