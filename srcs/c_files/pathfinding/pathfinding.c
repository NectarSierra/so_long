/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:04:30 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:50:06 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

int	head_progress(char **dupe_map)
{
	int	y;
	int	x;
	int	objectives_collected;

	y = 0;
	objectives_collected = 0;
	while (dupe_map[y])
	{
		x = 0;
		while (dupe_map[y][x])
		{
			if (dupe_map[y][x] == '3')
				objectives_collected += place_surrounding(dupe_map, x, y);
			x++;
		}
		y++;
	}
	return (objectives_collected);
}

void	replace_head(char **dupe_map)
{
	int	y;
	int	x;

	y = 0;
	while (dupe_map[y])
	{
		x = 0;
		while (dupe_map[y][x])
		{
			if (dupe_map[y][x] == '4')
				dupe_map[y][x] = '3';
			x++;
		}
		y++;
	}
}

int	check_for_head(char **dupe_map)
{
	int	x;
	int	y;

	y = 0;
	while (dupe_map[y])
	{
		x = 0;
		while (dupe_map[y][x])
		{
			if (dupe_map[y][x] == '3')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	pathfinding(t_param *param, t_map *map)
{
	char	**dupe_map;
	int		objectives_left;

	objectives_left = map->to_collect + 1;
	dupe_map = duping_map(map);
	if (!dupe_map)
		return (-1);
	while (check_for_head(dupe_map) && objectives_left != 0)
	{
		objectives_left -= head_progress(dupe_map);
		replace_head(dupe_map);
	}
	free_dupe_map(dupe_map);
	mlx_clear_window(param->xcon, param->win);
	return (objectives_left);
}
