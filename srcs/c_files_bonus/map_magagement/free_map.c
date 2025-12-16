/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:26:40 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:15:26 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files_bonus/header.h"

void	*free_map_hw(int *map_hw)
{
	free(map_hw);
	return (malloc_err());
}

void	*free_list_malloc(char **map, int *map_hw)
{
	int	y;

	y = 0;
	while (map[y] != NULL)
		free(map[y++]);
	free(map);
	free(map_hw);
	return (malloc_err());
}
