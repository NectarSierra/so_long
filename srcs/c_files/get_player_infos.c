/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 09:26:45 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:22:05 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/header.h"

int	*get_player_infos(t_map *map_e)
{
	int	y;
	int	x;
	int	*player_infos;

	player_infos = malloc(3 * sizeof(int));
	if (!player_infos)
		return (malloc_err());
	player_infos[2] = 0;
	y = 0;
	while (y < map_e->height)
	{
		x = 0;
		while (x < map_e->width)
		{
			if (map_e->map[y][x] == 'P')
			{
				player_infos[0] = y;
				player_infos[1] = x;
			}
			x++;
		}
		y++;
	}
	return (player_infos);
}
