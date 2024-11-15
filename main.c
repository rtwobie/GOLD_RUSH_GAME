#include "common.h"

void	sdl_init(void)
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

void ft_title_screen(void)
{
	printf("    ▗▄▄▖ ▗▄▖ ▗▖   ▗▄▄▄ \n");
	printf("   ▐▌   ▐▌ ▐▌▐▌   ▐▌  █ \n");
	printf("   ▐▌▝▜▌▐▌ ▐▌▐▌   ▐▌  █ \n");
	printf("   ▝▚▄▞▘▝▚▄▞▘▐▙▄▄▖▐▙▄▄▀ \n");
	printf("   ▗▄▄▖ ▗▖ ▗▖ ▗▄▄▖▗▖ ▗▖ \n");
	printf("   ▐▌ ▐▌▐▌ ▐▌▐▌   ▐▌ ▐▌ \n");
	printf("   ▐▛▀▚▖▐▌ ▐▌ ▝▀▚▖▐▛▀▜▌ \n");
	printf("   ▐▌ ▐▌▝▚▄▞▘▗▄▄▞▘▐▌ ▐▌ \n");
	printf("   =====================\n");
	printf("    ===================\n\n\n\n\n");
	printf("!PRESS ARROW KEYS TO MOVE!\n\n\n\n");
	printf("\nPINK_COWBOY: *Sigh...* This rusty old\n\
	     knife won't get me anywhere...\n\
	     unless I sneak up behind 'em!\n\n");
}

int	main(int argc, char *argv[])
{
	t_game game;
	t_app app;

	memset(&app, 0, sizeof(app));

	initSDL();
	if (argc != 2)
		return (1);
	ft_title_screen();
	init_game(&game);
	return (0);
}
