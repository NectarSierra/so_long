/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupe_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:17:39 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:19:57 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	free_dupe_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y])
			free(map[y]);
		y++;
	}
	free(map);
}

char	**allocate_dupe_map(t_map *map)
{
	int		y;
	char	**dupe_map;

	dupe_map = malloc((map->height + 1) * sizeof(char **));
	if (!dupe_map)
		return (malloc_err());
	y = 0;
	while (y < map->height)
	{
		dupe_map[y] = malloc((map->width + 1) * sizeof(char));
		if (!dupe_map[y])
		{
			free_dupe_map(dupe_map);
			return (malloc_err());
		}
		y++;
	}
	return (dupe_map);
}

char	**duping_map(t_map *map)
{
	char	**dupe_map;
	int		y;
	int		x;

	dupe_map = allocate_dupe_map(map);
	if (!dupe_map)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map[y][x])
		{
			dupe_map[y][x] = map->map[y][x];
			if (dupe_map[y][x] == 'P')
				dupe_map[y][x] = '3';
			x++;
		}
		dupe_map[y][x] = '\0';
		y++;
	}
	dupe_map[y] = NULL;
	return (dupe_map);
}
