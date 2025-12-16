/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:00:12 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:20:55 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	draw_collectible(t_param *param, int x, int y)
{
	int		*player_pos;
	t_map	*map_e;
	t_tiles	*tiles;

	player_pos = param->player_infos;
	map_e = param->map_e;
	tiles = param->tiles_e;
	if (y == player_pos[0] && x == player_pos[1])
	{
		map_e->map[y][x] = '0';
		map_e->to_collect--;
		if (map_e->to_collect == 0)
			draw_o_exit(param, map_e, tiles, player_pos);
	}
	mlx_put_image_to_window(param->xcon, param->win, tiles->img_c,
		((x - player_pos[1]) + 16 / 2) * tiles->tile_size,
		(((y - player_pos[0]) + ((16 / 2) + 1)) * tiles->tile_size));
}

void	draw_o_exit(t_param *p, t_map *map_e, t_tiles *tiles, int *player_pos)
{
	int	y;
	int	x;

	y = 1;
	while (y < map_e->height)
	{
		x = 0;
		while (x < map_e->width)
		{
			if (map_e->map[y][x] == 'E')
				mlx_put_image_to_window(p->xcon, p->win, tiles->img_e_o,
					((x - player_pos[1]) + 16 / 2) * tiles->tile_size,
					((y - player_pos[0]) + ((16 / 2) + 1)) * tiles->tile_size);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_param *param, int x, int y)
{
	int		*player_pos;
	t_map	*map_e;
	t_tiles	*tiles;

	player_pos = param->player_infos;
	map_e = param->map_e;
	tiles = param->tiles_e;
	if (map_e->to_collect > 0)
		mlx_put_image_to_window(param->xcon, param->win, tiles->img_e_c,
			((x - player_pos[1]) + 16 / 2) * tiles->tile_size,
			(((y - player_pos[0]) + ((16 / 2) + 1)) * tiles->tile_size));
	else
		mlx_put_image_to_window(param->xcon, param->win, tiles->img_e_o,
			((x - player_pos[1]) + 16 / 2) * tiles->tile_size,
			((y - player_pos[0]) + ((16 / 2) + 1)) * tiles->tile_size);
	if (y == player_pos[0] && x == player_pos[1] && map_e->to_collect == 0)
		end_loop(param);
}
