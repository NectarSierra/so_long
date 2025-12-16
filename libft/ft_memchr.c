/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:30:27 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/16 12:18:40 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*char_s;
	size_t		i;

	char_s = s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == (char)c)
			return ((char *)&char_s[i]);
		i++;
	}
	return (NULL);
}
