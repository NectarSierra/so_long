/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_hw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:31:24 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 09:36:35 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

int	comp_stored_w(int *h_w, int stored_w, char *result)
{
	int	x;

	x = 0;
	while (result[x] != '\0' && result[x] != '\n')
		x++;
	x++;
	if (x != stored_w)
	{
		write(2, "ERROR: map isn't rectangle.\n", 29);
		free(result);
		free(h_w);
		return (-1);
	}
	return (0);
}

int	gnl_hw(int *h_w, int fd)
{
	char	*result;
	int		stored_w;

	result = get_next_line(fd);
	if (result == NULL)
	{
		write(2, "ERROR: the map is empty.\n", 26);
		free(h_w);
		return (-1);
	}
	stored_w = get_width_map(result);
	while (result != NULL)
	{
		free(result);
		result = get_next_line(fd);
		h_w[0]++;
		h_w[1] = 0;
		if (result != NULL && comp_stored_w(h_w, stored_w, result) != 0)
			return (-1);
	}
	free(result);
	return (stored_w);
}

int	*allocate_setzero_hw(void)
{
	int	*hw;

	hw = malloc(2 * sizeof(int));
	if (!hw)
		return (malloc_err());
	hw[0] = 0;
	hw[1] = 0;
	return (hw);
}

int	*get_map_hw(char *path)
{
	int		fd;
	int		*h_w;
	int		stored_w;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (open_err(path));
	h_w = allocate_setzero_hw();
	stored_w = gnl_hw(h_w, fd);
	if (stored_w == -1)
		return (NULL);
	h_w[1] = stored_w;
	return (h_w);
}
