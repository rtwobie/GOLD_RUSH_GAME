/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_rush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:49:18 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/15 14:50:18 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_gold_drain(t_game *game)
{
	game->highscore = (game->highscore - 25);
	game->step_counter++;
	game->gold_rush--;
	printf("GOLD DRAIN: %i\n", game->gold_rush);
	if (game->gold_rush == 0)
	{
		printf("\n=====================\n");
		printf("AIN'T NO GOLD AROUND,\nSO YER SIX FEET DOWN!");
		printf("\n=====================\n");
		exit (0);
	}
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
