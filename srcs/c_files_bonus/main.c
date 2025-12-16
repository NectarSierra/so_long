/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:15:39 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:35:18 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files_bonus/header.h"

static int	free_all(t_param *param)
{
	if (param->player_infos)
		free(param->player_infos);
	if (param->map_e)
		free_list(param->map_e);
	if (param->win)
		mlx_destroy_window(param->xcon, param->win);
	if (param->xcon)
	{
		mlx_destroy_display(param->xcon);
		free(param->xcon);
	}
	if (param->tiles_e)
		free(param->tiles_e);
	free(param);
	return (-1);
}

int	execute_pathfinding(t_param *param)
{
	int	result;

	result = pathfinding(param, param->map_e);
	if (result != 0)
	{
		write(2, "ERROR: A total of ", 18);
		ft_putnbr_fd(result, 1);
		write(2, " objectives cannot be accesible, check for: E, C\n", 50);
		destroy_all_img(param);
		return (-1);
	}
	return (0);
}

int	initialize_game(t_param *param, char **argv)
{
	param->map_e = get_map(argv);
	if (param->map_e == NULL)
		return (free_all(param));
	param->xcon = mlx_init();
	if (param->xcon == NULL)
		return (free_all(param));
	param->win = mlx_new_window(param->xcon, 16 * 64, 17 * 64, "so_long");
	if (param->win == NULL)
		return (free_all(param));
	param->player_infos = get_player_infos(param->map_e);
	param->tiles_e = declare_tiles(param);
	if (!param->tiles_e)
		return (free_all(param));
	if (execute_pathfinding(param) == -1)
		return (free_all(param));
	pre_draw_map(param, param->map_e);
	mlx_hook(param->win, 2, 1L << 0, keyboard_input, param);
	mlx_hook(param->win, 17, 0, end_loop, param);
	mlx_loop(param->xcon);
	return (0);
}

void	clean_quit(t_param *param)
{
	free_list(param->map_e);
	mlx_destroy_window(param->xcon, param->win);
	free(param->player_infos);
	destroy_all_img(param);
	mlx_destroy_display(param->xcon);
	free(param->xcon);
	free(param->tiles_e);
	free(param);
}

int	main(int argc, char **argv)
{
	t_param		*param;

	if (argc == 2)
	{
		param = malloc(sizeof(t_param));
		if (!param)
		{
			perror("malloc failed");
			return (-1);
		}
		param->map_e = 0;
		param->xcon = 0;
		param->win = 0;
		param->player_infos = 0;
		param->tiles_e = 0;
		if (initialize_game(param, argv) == -1)
			return (-1);
		clean_quit(param);
		return (0);
	}
	return (argc_err());
}
