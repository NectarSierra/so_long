/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:40:58 by nsaillez          #+#    #+#             */
/*   Updated: 2024/12/16 12:40:58 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

char	*free_null(char *new_str)
{
	free(new_str);
	return (NULL);
}
