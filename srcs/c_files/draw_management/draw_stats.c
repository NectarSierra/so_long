/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:56:11 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 10:06:40 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	draw_stats_text(t_param *p, int col, int ste)
{
	char	*str;
	int		posx_s;
	int		posx_c;

	posx_s = (7 * p->tiles_e->tile_size);
	posx_c = (9 * p->tiles_e->tile_size);
	str = ft_itoa(col);
	if (str)
	{
		mlx_string_put(p->xcon, p->win, posx_c + 30, 58, 0xffffff, str);
		free(str);
	}
	str = ft_itoa(ste);
	if (str)
	{
		mlx_string_put(p->xcon, p->win, posx_s + 30, 58, 0xffffff, str);
		free(str);
	}
}

void	draw_stats(t_param *p, int ste, int col)
{
	void	*win;
	void	*xcon;
	int		posx_c;
	int		posx_s;

	mlx_set_font(p->xcon, p->win,
		"-misc-fixed-bold-r-semicondensed--13-120-75-75-c-60-iso8859-16");
	win = p->win;
	xcon = p->xcon;
	posx_s = (7 * p->tiles_e->tile_size);
	posx_c = (9 * p->tiles_e->tile_size);
	mlx_put_image_to_window(xcon, win, p->tiles_e->img_i_c, posx_c, -10);
	mlx_put_image_to_window(xcon, win, p->tiles_e->img_i_s, posx_s, -10);
	draw_stats_text(p, col, ste);
}
