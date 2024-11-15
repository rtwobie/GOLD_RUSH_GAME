#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h" // Deine Header-Datei mit t_game und anderen Prototypen

void can_move_verticalY(t_game *game)
{
    if (game->direction_v > 0)
    {
        // Prüfen, ob sich der vertikale Feind nach unten bewegen kann
        if (game->map[game->enemy_v_y + 1][game->enemy_v_x] == '1' ||
            game->map[game->enemy_v_y + 1][game->enemy_v_x] == 'E' ||
            game->map[game->enemy_v_y + 1][game->enemy_v_x] == 'C' ||
            game->map[game->enemy_v_y + 1][game->enemy_v_x] == 'X')
        {
            game->direction_v *= -1; // Richtung ändern
        }
        if (check_player_collisionY(game))
            exit(0);
    }
    else
    {
        // Prüfen, ob sich der vertikale Feind nach oben bewegen kann
        if (game->map[game->enemy_v_y - 1][game->enemy_v_x] == '1' ||
            game->map[game->enemy_v_y - 1][game->enemy_v_x] == 'E' ||
            game->map[game->enemy_v_y - 1][game->enemy_v_x] == 'C' ||
            game->map[game->enemy_v_y - 1][game->enemy_v_x] == 'X')
        {
            game->direction_v *= -1; // Richtung ändern
        }
        if (check_player_collisionY(game))
            exit(0);
    }
}

int check_player_collisionY(t_game *game)
{
    if (game->direction_v > 0)
    {
        if (game->map[game->enemy_v_y + 1][game->enemy_v_x] == 'P' ||
            game->map[game->enemy_v_y + game->direction_v][game->enemy_v_x] == 'P')
        {
            printf("\nBLUE_COWBOY: HAND OVER THE GOLD,\n	     YA VARMINT! *BANG*\n\n");
            printf("\n==========\nYOU'RE DEAD.\n==========\n\n");
            return (1);
        }
    }
    else
    {
        if (game->map[game->enemy_v_y - 1][game->enemy_v_x] == 'P' ||
            game->map[game->enemy_v_y + game->direction_v][game->enemy_v_x] == 'P')
        {
            printf("\nBLUE_COWBOY: Y'AIN'T GOIN' NOWHERE!\n	     *BANG*\n\n");
            printf("\n==========\nYOU'RE DEAD.\n==========\n\n");
            return (1);
        }
    }

    // Direkte Überprüfung der Spielerposition
    if (game->enemy_v_y == game->player_y && game->enemy_v_x == game->player_x)
    {
        printf("\nBLUE_COWBOY: HAND OVER THE GOLD,\n	     YA VARMINT! *BANG*\n\n");
        printf("\n==========\nYOU'RE DEAD.\n==========\n\n");
        return (1);
    }

    return (0);
}

void update_enemy_positionY(t_game *game)
{
    // Aktualisiere die Map-Daten
    game->map[game->enemy_v_y][game->enemy_v_x] = '0'; // Entferne Feind von der alten Position
    game->map[game->enemy_v_y + game->direction_v][game->enemy_v_x] = 'Y'; // Setze Feind an die neue Position

    // Aktualisiere die Position in der t_game-Struktur
    game->enemy_v_y += game->direction_v;
}

int move_enemy_Y(t_game *game)
{
    if (game->enemy_v_dead > 0) // Wenn der Feind "tot" ist, bewege ihn nicht
        return (0);

    can_move_verticalY(game);   // Überprüfe, ob sich der Feind bewegen kann
    update_enemy_positionY(game); // Aktualisiere die Feindposition
    return (1);
}

void render_enemy_vertical(SDL_Renderer *renderer, t_game *game)
{
    SDL_Rect enemy_rect = {
        game->enemy_v_x * TILE_SIZE,  // Berechne X-Position in Pixeln
        game->enemy_v_y * TILE_SIZE,  // Berechne Y-Position in Pixeln
        TILE_SIZE,                    // Breite des Feinds
        TILE_SIZE                     // Höhe des Feinds
    };

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blau für den vertikalen Feind
    SDL_RenderFillRect(renderer, &enemy_rect);        // Zeichne den Feind
}
