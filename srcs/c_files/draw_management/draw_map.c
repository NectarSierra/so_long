/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:03:47 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:58:17 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	case_draw(t_param *param, int x, int y)
{
	int		*player_pos;
	t_map	*map_e;
	t_tiles	*tiles;

	player_pos = param->player_infos;
	map_e = param->map_e;
	tiles = param->tiles_e;
	if (map_e->map[y][x] == '1')
		mlx_put_image_to_window(param->xcon, param->win, tiles->img_w,
			((x - player_pos[1]) + 16 / 2) * tiles->tile_size,
			(((y - player_pos[0]) + ((16 / 2) + 1)) * tiles->tile_size));
	if (map_e->map[y][x] == '0')
		mlx_put_image_to_window(param->xcon, param->win, tiles->img_g,
			((x - player_pos[1]) + 16 / 2) * tiles->tile_size,
			(((y - player_pos[0]) + ((16 / 2) + 1)) * tiles->tile_size));
	if (map_e->map[y][x] == 'C')
		draw_collectible(param, x, y);
	if (map_e->map[y][x] == 'E')
		draw_exit(param, x, y);
}

void	pre_draw_map(t_param *param, t_map *map_e)
{
	void	*xcon;
	void	*win;
	int		*player_pos;
	int		y;
	int		x;

	xcon = param->xcon;
	win = param->win;
	player_pos = param->player_infos;
	y = no_negative(player_pos[0] - 8);
	while (y < map_e->height && y < player_pos[0] + 8)
	{
		x = no_negative(player_pos[1] - 8);
		while (x < map_e->width && x < player_pos[1] + 8)
		{
			case_draw(param, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(xcon, win, param->tiles_e->img_p_f, 8 * 64, 9 * 64);
	param->map_e->map[param->player_infos[0]][param->player_infos[1]] = '0';
}

void	draw_map(t_param *param, t_map *map_e)
{
	int	y;
	int	x;
	int	*player_pos;

	player_pos = param->player_infos;
	mlx_clear_window(param->xcon, param->win);
	y = no_negative(player_pos[0] - 8);
	while (y < map_e->height && y < player_pos[0] + 8)
	{
		x = no_negative(player_pos[1] - 8);
		while (x < map_e->width && x < player_pos[1] + 8)
		{
			case_draw(param, x, y);
			x++;
		}
		y++;
	}
	ft_putnbr_fd(param->player_infos[2], 1);
	write(1, "\n", 1);
}
