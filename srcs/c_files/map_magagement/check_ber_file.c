/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_check_ber_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:12:49 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/05 11:56:00 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files/header.h"

void	*ber_err(char *path)
{
	write(2, "ERROR: ", 7);
	write(2, path, ft_strlen(path));
	write(2, " isn't a .ber file\n", 20);
	return (NULL);
}

int	check_ber_file(char *path)
{
	int		size;
	int		i;
	char	*ber;

	ber = ".ber";
	size = ft_strlen(path);
	i = 0;
	size--;
	if (path[size - 4])
	{
		while (i < 4)
		{
			if (path[size - i] != ber[3 - i])
				return (-1);
			i++;
		}
	}
	return (0);
}
