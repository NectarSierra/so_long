/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:55:52 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/16 12:15:03 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*char_s1;
	char	*char_s2;
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	char_s1 = (char *)s1;
	char_s2 = (char *)s2;
	while (i + 1 < n)
	{
		if (char_s1[i] != char_s2[i])
			return ((unsigned char)char_s1[i] - (unsigned char)char_s2[i]);
		i++;
	}
	return ((unsigned char)char_s1[i] - (unsigned char)char_s2[i]);
}
