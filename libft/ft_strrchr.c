/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:53:55 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/16 11:52:12 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int			s_size;
	int			i;
	const char	*ptr_s;
	char		ch;

	ch = (char)c;
	s_size = 0;
	while (s[s_size])
		s_size++;
	ptr_s = &s[s_size];
	i = s_size;
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)ptr_s);
		i--;
		ptr_s--;
	}
	if (ch == '\0')
		return ((char *)ptr_s);
	return ((void *)0);
}

/*#include <stdio.h>

int main()
{
	char *s = "whello orld ar";
	int c = 'w';
	printf("%s",ft_strrchr(s,c));
}*/
