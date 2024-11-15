#include "common.h"

void	init_sdl(void)
{
	int	window_flags;
	int	renderer_flags;
	
	window_flags = 0;
	renderer_flags = SDL_RENDERER_ACCELERATED;
	if (SDL_InitSubsystem(SDL_INIT_VIDEO) != 0)
	{
		printf("Couldn't Init SDL: %s\n", SDL_GetError());
		exit (1);
	}

	app.window = SDL_CreateWindow("Gold Rush", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SDL_GetError();
		exit (1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, 1, renderer_flags);
	if(!app.renderer)
	{
		printf("Failed to create Renderer: %s\n", SDL_GetError());
		exit (1);
	}
}

void init_game(t_game *game)
{
	game->max_x = 0;
	game->player_y = 0;
	game->player_x = 0;
	game->enemy_h_x = 0;
	game->enemy_h_y = 0;
	game->enemy_v_x = 0;
	game->enemy_v_y = 0;
	game->direction_v = 1;
	game->direction_h = 1;
	game->enemy_h_dead = 0;
	game->enemy_v_dead = 0;
	game->highscore = 0;
	game->coins_highscore = 0;
	game->kill_highscore = 0;
	game->step_counter = 0;
	game->gold_rush = 10;
}

int init_map(t_game *game, char *map_filename)
{
	int fd = open(map_filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Fehler: Öffnen der Map-Datei");
		return (1);
	}
	game->map = ft_read_map(fd, &game->max_y, &game->max_x);
	close(fd);
	if (!game->map)
	{
		perror("Fehler: Laden der Map fehlgeschlagen");
		return (1);
	}
	return (0);
}
