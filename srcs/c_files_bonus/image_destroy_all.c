/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destroy_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:16:41 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:35:26 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files_bonus/header.h"

void	destroy_all_img(t_param *p)
{
	t_tiles	*tiles_e;

	tiles_e = p->tiles_e;
	mlx_destroy_image(p->xcon, tiles_e->img_m_r);
	mlx_destroy_image(p->xcon, tiles_e->img_m_l);
	mlx_destroy_image(p->xcon, tiles_e->img_m_f);
	mlx_destroy_image(p->xcon, tiles_e->img_m_b);
	mlx_destroy_image(p->xcon, tiles_e->img_e_o);
	mlx_destroy_image(p->xcon, tiles_e->img_e_c);
	mlx_destroy_image(p->xcon, tiles_e->img_c);
	mlx_destroy_image(p->xcon, tiles_e->img_p_r);
	mlx_destroy_image(p->xcon, tiles_e->img_p_l);
	mlx_destroy_image(p->xcon, tiles_e->img_p_f);
	mlx_destroy_image(p->xcon, tiles_e->img_p_b);
	mlx_destroy_image(p->xcon, tiles_e->img_g);
	mlx_destroy_image(p->xcon, tiles_e->img_w);
	mlx_destroy_image(p->xcon, tiles_e->img_i_c);
	mlx_destroy_image(p->xcon, tiles_e->img_i_s);
}
