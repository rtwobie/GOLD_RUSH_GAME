#include <SDL2/SDL.h>
#include <stdio.h>
#include "game.h" // Deine Header-Datei mit t_game und anderen Prototypen

void can_move_horizontalX(t_game *game)
{
    if (game->direction_h > 0)
    {
        // Prüfen, ob sich der horizontale Feind nach rechts bewegen kann
        if (game->map[game->enemy_h_y][game->enemy_h_x + 1] == '1' ||
            game->map[game->enemy_h_y][game->enemy_h_x + 1] == 'E' ||
            game->map[game->enemy_h_y][game->enemy_h_x + 1] == 'C' ||
            game->map[game->enemy_h_y][game->enemy_h_x + 1] == 'Y')
        {
            game->direction_h *= -1; // Richtung ändern
        }
        if (check_player_collisionX(game))
            exit(0);
    }
    else
    {
        // Prüfen, ob sich der horizontale Feind nach links bewegen kann
        if (game->map[game->enemy_h_y][game->enemy_h_x - 1] == '1' ||
            game->map[game->enemy_h_y][game->enemy_h_x - 1] == 'E' ||
            game->map[game->enemy_h_y][game->enemy_h_x - 1] == 'C' ||
            game->map[game->enemy_h_y][game->enemy_h_x - 1] == 'Y')
        {
            game->direction_h *= -1; // Richtung ändern
        }
        if (check_player_collisionX(game))
            exit(0);
    }
}

int check_player_collisionX(t_game *game)
{
    // Kollision nach rechts prüfen
    if (game->direction_h > 0)
    {
        if (game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] == 'P')
        {
            printf("\nBLUE_COWBOY: HAND OVER THE GOLD,\n	     YA VARMINT! *BANG*\n\n");
            printf("\n==========\nYOU'RE DEAD.\n==========\n\n");
            return (1);
        }
    }
    else
    {
        // Kollision nach links prüfen
        if (game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] == 'P')
        {
            printf("\nBLUE_COWBOY: Y'AIN'T GOIN' NOWHERE!\n	     *BANG*\n\n");
            printf("\n==========\nYOU'RE DEAD.\n==========\n\n");
            return (1);
        }
    }

    // Direkte Überprüfung der Spielerposition
    if (game->enemy_h_y == game->player_y && game->enemy_h_x == game->player_x)
    {
        printf("\nBLUE_COWBOY: HAND OVER THE GOLD,\n	     YA VARMINT! *BANG*\n\n");
        printf("\n==========\nYOU'RE DEAD.\n==========\n\n");
        return (1);
    }

    return (0);
}

void update_enemy_positionX(t_game *game)
{
    // Aktualisiere die Map-Daten
    game->map[game->enemy_h_y][game->enemy_h_x] = '0'; // Entferne Feind von der alten Position
    game->map[game->enemy_h_y][game->enemy_h_x + game->direction_h] = 'X'; // Setze Feind an die neue Position

    // Aktualisiere die Position in der t_game-Struktur
    game->enemy_h_x += game->direction_h;
}

int move_enemy_X(t_game *game)
{
    if (game->enemy_h_dead > 0) // Wenn der Feind "tot" ist, bewege ihn nicht
        return (0);

    can_move_horizontalX(game);   // Überprüfe, ob sich der Feind bewegen kann
    update_enemy_positionX(game); // Aktualisiere die Feindposition
    return (1);
}

void render_enemy(SDL_Renderer *renderer, t_game *game)
{
    SDL_Rect enemy_rect = {
        game->enemy_h_x * TILE_SIZE,  // Berechne X-Position in Pixeln
        game->enemy_h_y * TILE_SIZE,  // Berechne Y-Position in Pixeln
        TILE_SIZE,                    // Breite des Feinds
        TILE_SIZE                     // Höhe des Feinds
    };

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rot für den Feind
    SDL_RenderFillRect(renderer, &enemy_rect);        // Zeichne den Feind
}
