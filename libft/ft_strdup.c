/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:07:57 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/16 11:13:29 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		s_len;
	char	*new_s;
	int		i;

	s_len = 0;
	while (s1[s_len])
		s_len++;
	new_s = malloc(s_len * sizeof(char) + 1);
	if (!new_s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

/*#include <stdio.h>
int main()
{
	char *s1 = "lorem ipsum dolor sit amet";
	printf("%s",ft_strdup(s1));
}*/
