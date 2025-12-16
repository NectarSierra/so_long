/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:30:56 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:15:15 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files_bonus/header.h"

int	get_width_map(char *result)
{
	int	stored_w;

	stored_w = 0;
	while (result[stored_w] != '\0' && result[stored_w] != '\n')
		stored_w++;
	stored_w++;
	return (stored_w);
}

int	*check_map_hw(int *map_hw)
{
	if (map_hw == NULL)
		return (NULL);
	if (map_hw[0] > 256 || map_hw[1] > 256)
	{
		write(2, "ERROR: map must be <= 256 in width & height!\n", 46);
		free(map_hw);
		return (NULL);
	}
	return (map_hw);
}

t_map	*allocate_map(t_map *map_element, char *argv)
{
	int		*map_hw;
	char	**map;
	int		i;

	i = 0;
	map_hw = get_map_hw(argv);
	if (check_map_hw(map_hw) == NULL)
		return (NULL);
	map = malloc((map_hw[0]) * sizeof(char **));
	if (!map)
		return (free_map_hw(map_hw));
	while (i < map_hw[0])
	{
		map[i] = malloc((map_hw[1]) * sizeof(char));
		if (!map[i])
			return (free_list_malloc(map, map_hw));
		i++;
	}
	i = 0;
	map_element->map = map;
	map_element->height = map_hw[0];
	map_element->width = (map_hw[1] - 1);
	free(map_hw);
	return (map_element);
}
