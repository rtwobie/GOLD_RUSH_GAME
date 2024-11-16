/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Furaido <Furaido@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:48:00 by Furaido           #+#    #+#             */
/*   Updated: 2024/11/15 07:55:04 by Furaido          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_surfaces	load_surface(void)
{
	t_surfaces surfaces;

	surfaces.wall = SDL_LoadBMP("assets/sprites/kaktus04.xpm");
	surfaces.player = SDL_LoadBMP("assets/sprites/cowboy_knife00.xpm");
	surfaces.floor = SDL_LoadBMP("assets/sprites/floor00.xpm");
	surfaces.exit = SDL_LoadBMP("assets/sprites/chest02.xpm");
	surfaces.coin = SDL_LoadBMP("assets/sprites/coin02.xpm");
	surfaces.enemy_y = SDL_LoadBMP("assets/sprites/cowboy_Y00.xpm");
	surfaces.enemy_x = SDL_LoadBMP("assets/sprites/cowboy_X00.xpm");

	// * add surface errorhandling here * //

	return (surfaces);
}

t_textures load_textures(void)
{
}

void render_cell(t_game *game, int x, int y)
{
    void *img = NULL;
    char cell = game->map[y][x];

    if (cell == '1')
        img = game->textures.wall;
    else if (cell == 'P')
        img = game->textures.player;
    else if (cell == 'C')
        img = game->textures.coin;
    else if (cell == 'E')
        img = game->textures.exit;
    else if (cell == '0')
        img = game->textures.floor;
    else if (cell == 'Y')
        img = game->textures.enemy_y;
    else if (cell == 'X')
        img = game->textures.enemy_x;

    if (img)
        mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
    else
        printf("Warning: Null image pointer for map[%d][%d]\n", y, x);
}

void render_row(t_game *game, int y)
{
    for (int x = 0; x < game->max_x; x++)
    {
        render_cell(game, x, y);
    }
}

void render_map(t_game *game)
{
    for (int y = 0; y < game->max_y; y++)
    {
        render_row(game, y);
    }
}
int load_game_assets(t_game *game)
{
    game->textures = load_textures(game->mlx);
    render_map(game);
    return (0);
}
