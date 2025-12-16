/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:23 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/22 11:10:05 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*de_malloc(char *new_s)
{
	new_s = malloc(1 * sizeof(char));
	if (!new_s)
		return (NULL);
	new_s[0] = '\0';
	return (new_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;
	size_t	i;

	if (!s)
		return (NULL);
	new_s = 0;
	if (start >= ft_strlen(s))
		return (de_malloc(new_s));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_s = malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_s[i] = s[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main()
{
	char *s = "";
	unsigned int start = 0;
	size_t len = 0;
	printf("%s",ft_substr(s,start,len));
}*/
