/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 09:47:54 by nsaillez          #+#    #+#             */
/*   Updated: 2025/03/06 13:15:05 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../h_files_bonus/header.h"

void	*malloc_err(void)
{
	perror("malloc failed");
	return (NULL);
}

void	*open_err(char *path)
{
	write(2, "ERROR: ", 7);
	write(2, path, ft_strlen(path));
	write(2, " couldn't be opened: ", 21);
	perror("");
	return (NULL);
}

int	argc_err(void)
{
	write(2, "ERROR: (not enough/too many) arguments\n", 40);
	return (-1);
}
