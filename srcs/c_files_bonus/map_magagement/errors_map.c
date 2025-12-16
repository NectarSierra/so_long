/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:34:32 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:15:24 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files_bonus/header.h"

void	write_map_obj_err(int *objs)
{
	write(2, "ERROR:\n", 7);
	if (objs[0] != 1)
	{
		write(2, "number of (P) Spawn-point: ", 27);
		ft_putnbr_fd(objs[0], 2);
		write(2, " (must be 1). \n", 15);
	}
	if (objs[1] < 1)
	{
		write(2, "number of (C) Collectible: ", 27);
		ft_putnbr_fd(objs[0], 2);
		write(2, " (must be >= 1). \n", 19);
	}
	if (objs[2] != 1)
	{
		write(2, "number of (E) Exit: ", 20);
		ft_putnbr_fd(objs[2], 2);
		write(2, " (must be 1). \n", 15);
	}
}

void	write_map_obj_na_err(void)
{
	write(2, "ERROR: A chararacter hasn't been recognize make sure ", 53);
	write(2, "that your map is only composed of those characters: ", 52);
	write(2, "0, 1, P, C, E, M.\n", 19);
}
