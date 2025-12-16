/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:49:41 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:10:22 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/header.h"

void	key_up(t_param *param)
{
	t_tiles	*tiles;

	tiles = param->tiles_e;
	if (param->map_e->map[param->player_infos[0] - 1]
		[param->player_infos[1]] != '1')
	{
		param->player_infos[0]--;
		param->player_infos[2]++;
		draw_map(param, param->map_e);
	}
	mlx_put_image_to_window(param->xcon, param->win, tiles->img_p_b,
		(16 / 2) * tiles->tile_size, ((16 / 2) + 1) * tiles->tile_size);
}

void	key_down(t_param *param)
{
	t_tiles	*tiles;

	tiles = param->tiles_e;
	if (param->map_e->map[param->player_infos[0] + 1]
		[param->player_infos[1]] != '1')
	{
		param->player_infos[0]++;
		param->player_infos[2]++;
		draw_map(param, param->map_e);
	}
	mlx_put_image_to_window(param->xcon, param->win, tiles->img_p_f,
		(16 / 2) * tiles->tile_size, ((16 / 2) + 1) * tiles->tile_size);
}

void	key_right(t_param *param)
{
	t_tiles	*tiles;

	tiles = param->tiles_e;
	if (param->map_e->map[param->player_infos[0]]
		[param->player_infos[1] - 1] != '1')
	{
		param->player_infos[1]--;
		param->player_infos[2]++;
		draw_map(param, param->map_e);
	}
	mlx_put_image_to_window(param->xcon, param->win, tiles->img_p_l,
		(16 / 2) * tiles->tile_size, ((16 / 2) + 1) * tiles->tile_size);
}

void	key_left(t_param *param)
{
	t_tiles	*tiles;

	tiles = param->tiles_e;
	if (param->map_e->map[param->player_infos[0]]
		[param->player_infos[1] + 1] != '1')
	{
		param->player_infos[1]++;
		param->player_infos[2]++;
		draw_map(param, param->map_e);
	}
	mlx_put_image_to_window(param->xcon, param->win, tiles->img_p_r,
		(16 / 2) * tiles->tile_size, ((16 / 2) + 1) * tiles->tile_size);
}

int	keyboard_input(int keycode, t_param *param)
{
	if (keycode == 65307)
		mlx_loop_end(param->xcon);
	if (keycode == 65362 || keycode == 119)
		key_up(param);
	if (keycode == 65364 || keycode == 115)
		key_down(param);
	if (keycode == 65361 || keycode == 97)
		key_right(param);
	if (keycode == 65363 || keycode == 100)
		key_left(param);
	return (0);
}
