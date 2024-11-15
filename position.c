/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:47:47 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/15 14:51:05 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_positions_Y(t_game *game)
{
	int x;
	int y;
	int found;

	x = 0;
	y = 0;
	found = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == 'Y')
			{
				game->enemy_v_x = x;
				game->enemy_v_y = y;
				found = 1;
				break;
			}
			x++;
		}
		if (found)
			break;
		y++;
	}
}
void find_positions_X(t_game *game)
{
	int x;
	int y;
	int found;

	x = 0;
	y = 0;
	found = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == 'X')
			{
				game->enemy_h_x = x;
				game->enemy_h_y = y;
				found = 1;
				break;
			}
			x++;
		}
		if (found)
			break;
		y++;
	}
}


void find_positions(t_game *game)
{
	int x;
	int y;
	int found;

	x = 0;
	y = 0;
	found = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				found = 1;
				break;
			}
			x++;
		}
		if (found)
			break;
		y++;
	}
}

void count_coins(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	game->count_coins = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x)
		{
			if (game->map[y][x] == 'C')
				game->count_coins++;
			x++;
		}
		y++;
	}
	game->found_coins = game->count_coins;
}
