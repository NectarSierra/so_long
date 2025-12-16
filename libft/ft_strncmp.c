/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:05:09 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/16 10:51:16 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i + 1 < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
		i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char *s1 = "test\200";
	char *s2 = "test\0";
	size_t n = 6;
	printf("%d\n",ft_strncmp(s1,s2,n));
	printf("%d\n",strncmp(s1,s2,n));
}*/
