/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:08:57 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/16 09:57:45 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;
	size_t	dstlen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	dstlen = 0;
	while (dst[dstlen])
		dstlen++;
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	i = 0;
	while ((i + dstlen) < dstsize -1 && src[i])
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (srclen + dstlen);
}
