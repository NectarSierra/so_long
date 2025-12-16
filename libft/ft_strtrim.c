/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:04:06 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/22 12:00:56 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	len = ft_strlen(s1 + start);
	while (len > 0 && ft_strchr(set, s1[start + len - 1]))
		len--;
	str = ft_substr(s1, start, len);
	return (str);
}

/*#include <stdio.h>
int main()
{
	char *s1 = "";
	char *set = "";
	printf("res:%s\n", ft_strtrim(s1,set));
}*/
