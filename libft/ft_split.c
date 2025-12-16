/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:09:37 by nsaillez          #+#    #+#             */
/*   Updated: 2024/10/22 12:20:34 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	list_size(char const *s, char c)
{
	size_t	num_strs;
	size_t	i;

	num_strs = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			num_strs++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (num_strs);
}

static char	*new_word(char const *s, char c, int *index)
{
	char	*word;
	int		word_len;
	int		start;
	int		i;

	i = 0;
	start = *index;
	word_len = 0;
	while (s[start] == c)
		start++;
	while (s[start + word_len] != c && s[start + word_len])
		word_len++;
	word = malloc((word_len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < word_len)
		word[i++] = s[start++];
	word[i] = '\0';
	*index = start;
	return (word);
}

static void	*free_listptr(char **list_ptr, size_t num_str)
{
	size_t	i;

	i = 0;
	while (i < num_str)
	{
		free(list_ptr[i]);
		i++;
	}
	free(list_ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**list_str;
	size_t	num_str;
	int		index;
	size_t	i;

	if (!s)
		return (NULL);
	index = 0;
	i = 0;
	num_str = list_size(s, c);
	list_str = malloc((num_str + 1) * sizeof(char *));
	if (!list_str)
		return (NULL);
	while (i < num_str)
	{
		list_str[i] = new_word(s, c, &index);
		if (!list_str[i])
		{
			free_listptr(list_str, i);
			return (NULL);
		}
		i++;
	}
	list_str[i] = NULL;
	return (list_str);
}

/*int main()
{

	char **result;
	int i = 0;
	result = ft_split("hello!", ' ');
	if (!result)
		printf ("error");
	else
	{
		while (result[i])
		{
			printf("%s\n",result[i]);
			i++;
		}
	}
}*/
