/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:21:08 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:15:21 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files_bonus/header.h"

int	*case_manager(char c, int *objs)
{
	if (c == 'P')
		objs[0]++;
	else if (c == 'C')
		objs[1]++;
	else if (c == 'E')
		objs[2]++;
	else if (c != '0' && c != '1' && c != 'M')
	{
		free(objs);
		return (NULL);
	}
	return (objs);
}

int	*get_all_obj(t_map *map, int *objs)
{
	int	y;
	int	x;

	y = 0;
	objs[0] = 0;
	objs[1] = 0;
	objs[2] = 0;
	while (y < map->height)
	{
		x = 0;
		while (map->map[y][x])
		{
			objs = case_manager(map->map[y][x], objs);
			if (!objs)
				return (NULL);
			x++;
		}
		y++;
	}
	return (objs);
}

int	free_list_int(t_map *map_element)
{
	int	y;

	y = 0;
	while (y < map_element->height)
		free (map_element->map[y++]);
	free (map_element->map);
	free (map_element);
	return (-1);
}

int	check_map_obj(t_map *map_element)
{
	int	*objs;
	int	collectible;

	objs = malloc(3 * sizeof(int));
	if (!objs)
	{
		perror("malloc failed");
		return (free_list_int(map_element));
	}
	objs = get_all_obj(map_element, objs);
	if (objs == NULL)
	{
		write_map_obj_na_err();
		return (free_list_int(map_element));
	}
	collectible = objs[1];
	if (objs[0] != 1 || objs[1] < 1 || objs[2] != 1)
	{
		write_map_obj_err(objs);
		free(objs);
		return (free_list_int(map_element));
	}
	free(objs);
	return (collectible);
}
