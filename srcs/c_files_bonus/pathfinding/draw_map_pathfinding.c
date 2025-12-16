/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_pathfinding.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:13:33 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:14:04 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	draw_2x2_pixels(t_param *param, int x, int y, int color)
{
	mlx_pixel_put(param->xcon, param->win, x, y, color);
	mlx_pixel_put(param->xcon, param->win, x + 1, y, color);
	mlx_pixel_put(param->xcon, param->win, x, y + 1, color);
	mlx_pixel_put(param->xcon, param->win, x + 1, y + 1, color);
}

void	case_color(t_param *param, char c, int x, int y)
{
	int		ofx;
	int		ofy;

	ofx = (8 * 64) - (param->map_e->width * 2);
	ofy = (8 * 64) - (param->map_e->height * 2);
	if (c == 'E')
		draw_2x2_pixels(param, (x * 4) + ofx, (y * 4) + ofy, 0xff0004);
	if (c == 'C')
		draw_2x2_pixels(param, (x * 4) + ofx, (y * 4) + ofy, 0xff0004);
	if (c == '1')
		draw_2x2_pixels(param, (x * 4) + ofx, (y * 4) + ofy, 0x171614);
	if (c == '3')
		draw_2x2_pixels(param, (x * 4) + ofx, (y * 4) + ofy, 0x005c09);
	if (c == '2')
		draw_2x2_pixels(param, (x * 4) + ofx, (y * 4) + ofy, 0x00ff1a);
}

void	draw_map_pathfinding(t_param *param, char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			case_color(param, map[y][x], x, y);
			x++;
		}
		y++;
	}
}
