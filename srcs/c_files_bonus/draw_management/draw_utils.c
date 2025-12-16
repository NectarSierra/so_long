/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:07:13 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:15:03 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files_bonus/header.h"

int	end_loop(t_param *param)
{
	mlx_loop_end(param->xcon);
	return (0);
}

int	no_negative(int a)
{
	int	result;

	result = a - 8;
	if (result < 0)
		result = 0;
	return (result);
}

void	bad_ending(t_param *param)
{
	write(1, "Unfortunately, you got eaten by a minotaur, but you took ", 57);
	ft_putnbr_fd(param->player_infos[2], 1);
	write(1, " steps before that happened!\n", 30);
	end_loop(param);
}
