/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:26:08 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/22 11:13:26 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	new_s = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	i = 0;
	while (i < s1_size)
	{
		new_s[i] = s1[i];
		i++;
	}
	while (i < s2_size + s1_size)
	{
		new_s[i] = s2[i - s1_size];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*#include <stdio.h>

int main()
{
	char *s1 = "Hello";
	char *s2 = "_there!";
	printf("%s",ft_strjoin(s1,s2));
}*/
