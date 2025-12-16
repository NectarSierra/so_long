/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:16:41 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 11:01:28 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifndef DRAW_PATHFINDING
#  define DRAW_PATHFINDING 1
# endif

# include "structs.h"

# include "../../libft/libft.h"
# include "../../minilibx-linux/mlx.h"
# include "../../minilibx-linux/mlx_int.h"
# include <stdio.h>

void	*malloc_err(void);
void	*open_err(char *path);

int		check_ber_file(char *path);
void	*ber_err(char *path);

int		get_width_map(char *result);
int		compare_stored_width(int *height_width, int stored_width, char *result);
int		*declare_setzero_hw(void);
int		*get_map_hw(char *path);
t_map	*allocate_map(t_map *map_element, char *argv);

t_map	*get_map(char **argv);
char	**set_values(t_map *map_element, char *path);

int		check_map_borders(t_map *map_element);
int		check_map_obj(t_map *map_element);

void	*free_list(t_map *map_element);

int		pathfinding(t_param *param, t_map *map);
t_tiles	*declare_tiles(t_param *param);
void	destroy_all_img(t_param *param);

void	draw_map(t_param *param, t_map *map_element);

int		keyboard_input(int keycode, t_param *param);
int		end_loop(t_param *param);
void	*free_map_hw(int *map_hw);
void	*free_list_malloc(char **map, int *map_hw);
int		free_param_err(t_param *param);
int		*get_player_infos(t_map *map_e);
void	free_map_e(t_map *map_e);

void	write_map_obj_na_err(void);
void	write_map_obj_err(int *objs);

void	pre_draw_map(t_param *param, t_map *map_e);
int		argc_err(void);

int		*get_map_hw(char *path);

void	*open_err(char *path);
void	*malloc_err(void);
int		argc_err(void);

void	draw_stats_text(t_param *p, int col, int ste);
void	draw_stats(t_param *p, int ste, int col);

void	draw_exit(t_param *param, int x, int y);
void	draw_o_exit(t_param *p, t_map *map_e, t_tiles *tiles, int *player_pos);
void	draw_collectible(t_param *param, int x, int y);
void	draw_minotaur(t_param *param, int x, int y);
int		no_negative(int a);
void	bad_ending(t_param *param);

void	draw_map_pathfinding(t_param *param, char **map);

int		place_surrounding(char **dupe_map, int x, int y);

char	**duping_map(t_map *map);
void	free_dupe_map(char **map);

#endif