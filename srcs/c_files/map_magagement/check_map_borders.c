/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_borders.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:07:38 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 09:51:51 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

int	check_all_borders(t_map *map_element)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_element->map[y][x])
	{
		if (map_element->map[y][x] != '1')
			return (-1);
		if (map_element->map[map_element->height - 1][x] != '1')
			return (-1);
		x++;
	}
	y = 1;
	x = 0;
	while (y < map_element->height - 3)
	{
		if (map_element->map[y][0] != '1'
			|| map_element->map[y][map_element->width - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	check_map_borders(t_map *map_element)
{
	if (check_all_borders(map_element) == -1)
	{
		free_list(map_element);
		write(2, "ERROR: The map border must only be compose of \'1\'.\n", 52);
		return (-1);
	}
	return (0);
}
