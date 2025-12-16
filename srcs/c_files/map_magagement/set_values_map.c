/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:28:26 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 09:21:30 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

char	*put_in_line(char *map, char *line)
{
	int	x;

	x = 0;
	while (line[x] && line[x] != '\n')
	{
		map[x] = line[x];
		x++;
	}
	map[x] = '\0';
	return (map);
}

int	free_list_set_values(t_map *map_element)
{
	int	y;

	y = 0;
	while (y < map_element->height)
	{
		if (map_element->map[y])
			free (map_element->map[y]);
		y++;
	}
	free (map_element->map);
	free (map_element);
	perror("malloc failed");
	return (-1);
}

int	gnl_set_values(t_map *map_element, int fd)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	if (!line)
		return (free_list_set_values(map_element));
	map_element->map[y] = put_in_line(map_element->map[y], line);
	y++;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			map_element->map[y] = put_in_line(map_element->map[y], line);
			y++;
		}
	}
	if (y < map_element->height)
		return (free_list_set_values(map_element));
	free(line);
	return (0);
}

char	**set_values(t_map *map_element, char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (open_err(path));
	if (gnl_set_values(map_element, fd) != 0)
		return (NULL);
	return (map_element->map);
}
