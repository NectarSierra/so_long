/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_surrounding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:15:45 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:54:42 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

int	check_accessible(char c)
{
	if (c != '1' && c != '2')
		return (1);
	return (-1);
}

int	check_collectible(char c)
{
	if (c == 'E' || c == 'C')
		return (1);
	return (-1);
}

int	pos_up_down_left_right(char **dupe_map, int x, int y, int obj)
{
	if (check_accessible(dupe_map[y + 1][x]) == 1)
	{
		if (check_collectible(dupe_map[y + 1][x]) == 1)
			obj++;
		dupe_map[y + 1][x] = '4';
	}
	if (check_accessible(dupe_map[y][x + 1]) == 1)
	{
		if (check_collectible(dupe_map[y][x + 1]) == 1)
			obj++;
		dupe_map[y][x + 1] = '4';
	}
	if (check_accessible(dupe_map[y - 1][x]) == 1)
	{
		if (check_collectible(dupe_map[y - 1][x]) == 1)
			obj++;
		dupe_map[y - 1][x] = '4';
	}
	if (check_accessible(dupe_map[y][x - 1]) == 1)
	{
		if (check_collectible(dupe_map[y][x - 1]) == 1)
			obj++;
		dupe_map[y][x - 1] = '4';
	}
	return (obj);
}

int	place_surrounding(char **dupe_map, int x, int y)
{
	int	objectives;

	objectives = 0;
	objectives = pos_up_down_left_right(dupe_map, x, y, objectives);
	dupe_map[y][x] = '2';
	return (objectives);
}
