#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define TILE_SIZE 32

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *player_texture;
    SDL_Texture *enemy_texture;
    SDL_Texture *coin_texture;
    SDL_Texture *bg_texture;
    int player_x;
    int player_y;
    int map_width;
    int map_height;
    char **map;
} Game;

int init_game(Game *game, char *map_filename) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create window
    game->window = SDL_CreateWindow("Gold Rush", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, SDL_WINDOW_SHOWN);
    if (!game->window) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Create renderer
    game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);
    if (!game->renderer) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Load textures
    game->player_texture = SDL_CreateTextureFromSurface(game->renderer, SDL_LoadBMP("player.bmp"));
    game->enemy_texture = SDL_CreateTextureFromSurface(game->renderer, SDL_LoadBMP("enemy.bmp"));
    game->coin_texture = SDL_CreateTextureFromSurface(game->renderer, SDL_LoadBMP("coin.bmp"));
    game->bg_texture = SDL_CreateTextureFromSurface(game->renderer, SDL_LoadBMP("background.bmp"));

    if (!game->player_texture || !game->enemy_texture || !game->coin_texture || !game->bg_texture) {
        printf("Failed to load textures! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void render_game(Game *game) {
    SDL_RenderClear(game->renderer);

    // Render the background
    SDL_RenderCopy(game->renderer, game->bg_texture, NULL, NULL);

    // Render the map
    for (int y = 0; y < game->map_height; y++) {
        for (int x = 0; x < game->map_width; x++) {
            if (game->map[y][x] == 'P') {
                SDL_Rect dst_rect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                SDL_RenderCopy(game->renderer, game->player_texture, NULL, &dst_rect);
            }
            else if (game->map[y][x] == 'X') {
                SDL_Rect dst_rect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                SDL_RenderCopy(game->renderer, game->enemy_texture, NULL, &dst_rect);
            }
            else if (game->map[y][x] == 'C') {
                SDL_Rect dst_rect = {x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};
                SDL_RenderCopy(game->renderer, game->coin_texture, NULL, &dst_rect);
            }
        }
    }

    SDL_RenderPresent(game->renderer);
}

void close_game(Game *game) {
    SDL_DestroyTexture(game->player_texture);
    SDL_DestroyTexture(game->enemy_texture);
    SDL_DestroyTexture(game->coin_texture);
    SDL_DestroyTexture(game->bg_texture);
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    SDL_Quit();
}

int main(int argc, char **argv) {
    Game game;
    if (argc != 2) {
        printf("Usage: %s <map_filename>\n", argv[0]);
        return -1;
    }

    // Initialize game and load map (you should implement map loading)
    if (init_game(&game, argv[1]) < 0) {
        return -1;
    }

    // Main game loop
    int quit = 0;
    SDL_Event e;
    while (!quit) {
        // Handle events
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            else if (e.type == SDL_KEYDOWN) {
                // Handle key events here (for movement)
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        // Move player up
                        break;
                    case SDLK_DOWN:
                        // Move player down
                        break;
                    case SDLK_LEFT:
                        // Move player left
                        break;
                    case SDLK_RIGHT:
                        // Move player right
                        break;
                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                }
            }
        }

        // Update game state (movement, collisions, etc.)

        // Render game state
        render_game(&game);
    }

    // Clean up and close the game
    close_game(&game);
    return 0;
}
