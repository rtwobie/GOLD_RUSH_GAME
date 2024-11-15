#include "so_long.h"
#include <SDL2/SDL.h>  // SDL2 Header für Events und Rendering

// Diese Funktion wird aufgerufen, wenn eine Taste gedrückt wird
int key_hook(SDL_Keycode keycode, t_game *game)
{
    int moved = 0;

    if (keycode == SDLK_UP)
        moved = move_player(game, game->player_x, (game->player_y - 1));
    else if (keycode == SDLK_DOWN)
        moved = move_player(game, game->player_x, (game->player_y + 1));
    else if (keycode == SDLK_LEFT)
        moved = move_player(game, (game->player_x - 1), game->player_y);
    else if (keycode == SDLK_RIGHT)
        moved = move_player(game, (game->player_x + 1), game->player_y);
    else if (keycode == SDLK_ESCAPE)  // ESC-Taste für das Beenden des Spiels
        exit(0);

    // Wenn sich der Spieler bewegt hat, führen wir das Gold-Drain und das Rendering durch
    if (moved)
    {
        ft_gold_drain(game);
        render_map(game);  // Diese Funktion muss in SDL angepasst werden
    }

    return 0;
}

// Funktion, um die Position des Spielers zu aktualisieren
void move_player_update(t_game *game, int new_x, int new_y)
{
    game->map[game->player_y][game->player_x] = '0';  // Setze alte Position auf leer
    game->map[new_y][new_x] = 'P';  // Setze neue Position auf Spieler
    game->player_x = new_x;
    game->player_y = new_y;
}

// Bewege die Feinde
void move_enemies(t_game *game)
{
    if (game->enemy_h_dead == 0)
        move_enemy_X(game);  // Diese Funktionen müssen für SDL umgeschrieben werden
    if (game->enemy_v_dead == 0)
        move_enemy_Y(game);  // Diese Funktionen müssen für SDL umgeschrieben werden
}

// Hauptbewegungsfunktion des Spielers
int move_player(t_game *game, int new_x, int new_y)
{
    // Prüfe, ob das Spiel zu Ende ist
    if (!check_end_game(game, new_x, new_y))
        return 0;

    // Prüfe, ob der neue Ort blockiert ist (z. B. durch Wände oder Feinde)
    if (is_blocked(game, new_x, new_y))
        return 0;

    // Prüfe auf Kollisionen mit Feinden
    check_enemy_collisions(game, new_x, new_y);

    // Sammle Münzen
    collect_coin(game, new_x, new_y);

    // Aktualisiere die Position des Spielers
    move_player_update(game, new_x, new_y);

    // Bewege die Feinde
    move_enemies(game);

    return 1;
}
