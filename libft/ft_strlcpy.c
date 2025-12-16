/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:30:22 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/15 17:35:15 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

/*#include <string.h>
#include <stdio.h>
int main()
{
	size_t dstsize = 15;
	char *src = "";
	char dst[dstsize];
	char dst2[dstsize];
	printf("----mine:%lu\n",ft_strlcpy(dst,src,dstsize));
	printf("----mine:%s\n",dst);
	printf("expected:%lu\n",strlcpy(dst2,src,dstsize));
	printf("expected:%s\n",dst2);
}*/
