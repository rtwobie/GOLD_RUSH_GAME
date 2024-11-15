#include "game.h" // Deine Header-Datei

int check_end_game(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == 'E' && game->found_coins == 0)
    {
        if (game->enemy_h_dead == 0 && game->enemy_v_dead == 0)
        {
            printf("\nPINK_COWBOY: *Tch...* I didn't even\n\
	     need this damn rusty thing\n\
	     to get through!\n\n");
            printf("\nGOOD JOB! c:\n\n");
        }
        else
        {
            printf("\nPINK_COWBOY: *Pew...* that was close...\n\n");
            printf("\nTOO BAD... :c\n\n");
        }

        // Zeige Punkte an
        printf("COINS: %i   +%i\n", game->count_coins, (game->count_coins * 500));
        printf("STEPS: %i  %i\n", game->step_counter, (game->step_counter * -25));
        printf("KILLS: %i   %i\n", (game->enemy_h_dead + game->enemy_v_dead),
               ((game->enemy_h_dead + game->enemy_v_dead) * -250));
        printf("=========\nHIGHSCORE: %i\n=========\n\n", game->highscore);

        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Game Over",
            "Game Completed! Check your stats in the console.", NULL);

        SDL_Quit();
        exit(0);
    }
    return 1;
}

int is_blocked(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1' || game->map[new_y][new_x] == 'E')
        return 1;

    if ((game->map[game->player_y][(game->player_x - 1)] == 'X') && ((game->player_x - 1) != new_x))
        return 1;

    if ((game->map[(game->player_y + 1)][game->player_x] == 'Y') && ((game->player_y + 1) != new_y))
        return 1;

    return 0;
}

void check_enemy_collisions(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x - 1] == 'X')
    {
        printf("\nBLUE_COWBOY: *Oof...*\n\n");
        printf("\nCOWBOY KILLED  -250\n\n");
        game->highscore -= 250;
        game->enemy_h_dead++;

        // Entferne horizontalen Feind aus der Map
        game->map[new_y][new_x - 1] = '0';
    }

    if (game->map[new_y + 1][new_x] == 'Y')
    {
        printf("\nBLUE_COWBOY: *Arrg!*\n\n");
        printf("\nCOWBOY KILLED  -250\n\n");
        game->highscore -= 250;
        game->enemy_v_dead++;

        // Entferne vertikalen Feind aus der Map
        game->map[new_y + 1][new_x] = '0';
    }
}

void collect_coin(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == 'C')
    {
        game->gold_rush = 10;
        game->map[new_y][new_x] = '0'; // Entferne die Münze aus der Map
        game->found_coins--;
        game->highscore += 500;

        // Ausgabe in der Konsole
        printf("\nCOIN COLLECTED +500\n\n");
    }
}
