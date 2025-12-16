/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:24:43 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/05 16:17:07 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	char	**map;
	int		to_collect;
	int		height;
	int		width;
}	t_map;

typedef struct s_tiles
{
	int		tile_size;
	void	*img_m_r;
	void	*img_m_l;
	void	*img_m_f;
	void	*img_m_b;
	void	*img_e_o;
	void	*img_e_c;
	void	*img_c;
	void	*img_p_r;
	void	*img_p_l;
	void	*img_p_b;
	void	*img_p_f;
	void	*img_g;
	void	*img_w;
	void	*img_i_s;
	void	*img_i_c;
}	t_tiles;

typedef struct s_param
{
	void	*xcon;
	void	*win;
	int		*player_infos;
	t_map	*map_e;
	t_tiles	*tiles_e;
}	t_param;
