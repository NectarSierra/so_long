/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:27:39 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 09:52:15 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	*free_list(t_map *map_element)
{
	int	y;

	y = 0;
	while (y < map_element->height)
		free (map_element->map[y++]);
	free (map_element->map);
	free (map_element);
	return (NULL);
}

t_map	*get_map(char **argv)
{
	t_map	*map_element;
	int		collectible;

	map_element = malloc(sizeof(t_map));
	if (check_ber_file(argv[1]) != 0)
	{
		free(map_element);
		return (ber_err(argv[1]));
	}
	if (allocate_map(map_element, argv[1]) == NULL)
	{
		free(map_element);
		return (NULL);
	}
	if (set_values(map_element, argv[1]) == NULL)
		return (NULL);
	if (check_map_borders(map_element) != 0)
		return (NULL);
	collectible = check_map_obj(map_element);
	if (collectible < 1)
		return (NULL);
	map_element->to_collect = collectible;
	return (map_element);
}
