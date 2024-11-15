#include "common.h"

void	ft_title_screen(void)
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

void	cleanup(void)
{
	if (app.window)
		SDL_DestroyWindow(app.window);
	if (app.renderer)
		SDL_DestroyRenderer(app.renderer);
	SDL_Quit();
}

int	main(int argc, char *argv[])
{
	t_game	game;
	t_app	app;

	if (argc != 2)
		return (1);
	memset(&app, 0, sizeof(app));
	init_sdl();

	atexit(cleanup);

	ft_title_screen();
	init_game(&game);
	if (init_map(&game, argv[argc - 1]))
		return (1);

	find_positions(&game));
	find_positions_y(&game);
	find_positions_x(&game);
	count_coins(&game);
	load_game_assets(&game);
	start_game(&game);
	free(game.map);
	return (0);
}
