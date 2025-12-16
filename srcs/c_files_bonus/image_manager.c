/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:53:09 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:35:24 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files_bonus/header.h"

void	declare_minotaur_tiles(t_param *p, void **tiles_list, int w, int h)
{
	p->tiles_e->img_m_r = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/minotaur_right.xpm", &w, &h);
	p->tiles_e->img_m_l = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/minotaur_left.xpm", &w, &h);
	p->tiles_e->img_m_f = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/minotaur_front.xpm", &w, &h);
	p->tiles_e->img_m_b = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/minotaur_back.xpm", &w, &h);
	tiles_list[0] = p->tiles_e->img_m_r;
	tiles_list[1] = p->tiles_e->img_m_l;
	tiles_list[2] = p->tiles_e->img_m_f;
	tiles_list[3] = p->tiles_e->img_m_b;
}

void	declare_player_tiles(t_param *p, void **tiles_list, int w, int h)
{
	p->tiles_e->img_p_r = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/player_right.xpm", &w, &h);
	p->tiles_e->img_p_l = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/player_left.xpm", &w, &h);
	p->tiles_e->img_p_b = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/player_back.xpm", &w, &h);
	p->tiles_e->img_p_f = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/player_front.xpm", &w, &h);
	tiles_list[4] = p->tiles_e->img_p_r;
	tiles_list[5] = p->tiles_e->img_p_l;
	tiles_list[6] = p->tiles_e->img_p_f;
	tiles_list[7] = p->tiles_e->img_p_b;
}

void	declare_objectives_tiles(t_param *p, void **tiles_list, int w, int h)
{
	p->tiles_e->img_e_o = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/exit_opened.xpm", &w, &h);
	p->tiles_e->img_e_c = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/exit_closed.xpm", &w, &h);
	p->tiles_e->img_c = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/collectible.xpm", &w, &h);
	p->tiles_e->img_g = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/grass.xpm", &w, &h);
	p->tiles_e->img_w = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/wall.xpm", &w, &h);
	p->tiles_e->img_i_c = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/icon_collectible.xpm", &w, &h);
	p->tiles_e->img_i_s = mlx_xpm_file_to_image(p->xcon,
			"./srcs/xpm/icon_steps.xpm", &w, &h);
	tiles_list[8] = p->tiles_e->img_e_o;
	tiles_list[9] = p->tiles_e->img_e_c;
	tiles_list[10] = p->tiles_e->img_c;
	tiles_list[11] = p->tiles_e->img_g;
	tiles_list[12] = p->tiles_e->img_w;
	tiles_list[13] = p->tiles_e->img_i_c;
	tiles_list[14] = p->tiles_e->img_i_s;
}

int	check_tiles_list(t_param *p, void **tiles_list)
{
	int	i;

	i = 0;
	while (i < 15)
	{
		if (tiles_list[i] == NULL)
		{
			i = 0;
			while (i < 15)
			{
				if (tiles_list[i] != NULL)
					mlx_destroy_image(p->xcon, tiles_list[i]);
				i++;
			}
			return (-1);
		}
		i++;
	}
	return (0);
}

t_tiles	*declare_tiles(t_param *p)
{
	t_tiles	*tiles_e;
	int		tiles_size;
	void	*tiles_list[15];
	int		w;
	int		h;

	tiles_e = malloc(sizeof(t_tiles));
	if (!tiles_e)
		return (malloc_err());
	p->tiles_e = tiles_e;
	tiles_size = 64;
	w = tiles_size;
	h = tiles_size;
	tiles_e->tile_size = tiles_size;
	declare_minotaur_tiles(p, tiles_list, w, h);
	declare_player_tiles(p, tiles_list, w, h);
	declare_objectives_tiles(p, tiles_list, w, h);
	if (check_tiles_list(p, tiles_list) == -1)
	{
		free(tiles_e);
		return (NULL);
	}
	return (tiles_e);
}
