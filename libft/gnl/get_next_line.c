/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:32:05 by nsaillez          #+#    #+#             */
/*   Updated: 2024/12/16 13:09:29 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_declare_res(char *str1, char *str2, int length)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (j < length && str2[j - 1] != '\n')
		j++;
	res = malloc((i + j + 1) * sizeof(char));
	if (!res)
		return (NULL);
	return (res);
}

char	*ft_join(char *str1, char *str2, int length)
{
	char	*res;
	int		i;
	int		j;

	res = ft_declare_res(str1, str2, length);
	if (!res)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	j = 0;
	while (j < length && str2[j - 1] != '\n')
	{
		res[i + j] = str2[j];
		j++;
	}
	res[i + j] = '\0';
	free(str1);
	return (res);
}

char	*ft_trim_front(char *buffer, int length, char *new_str)
{
	int		i;

	i = 0;
	while ((i + length) < BUFFER_SIZE)
	{
		buffer[i] = buffer[i + length];
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	return (new_str);
}

char	*ft_search_nl(int fd, char *buffer, int read_s, char *new_str)
{
	int		i;

	while (1)
	{
		new_str = ft_join(new_str, buffer, BUFFER_SIZE);
		if (!new_str)
			return (NULL);
		i = 0;
		while (buffer[i] != '\n' && buffer[i])
			i++;
		if (buffer[i] == '\n' && buffer[i])
			return (ft_trim_front(buffer, i + 1, new_str));
		clear_buffer(buffer);
		read_s = read(fd, buffer, BUFFER_SIZE);
		i = 0;
		while (buffer[i] != '\n' && buffer[i])
			i++;
		if (read_s < BUFFER_SIZE && read_s > 0)
			new_str = ft_join(new_str, buffer, read_s);
		if (read_s == -1)
			return (free_null(new_str));
		if (read_s == 0 || (read_s < BUFFER_SIZE && read_s > 0))
			return (ft_trim_front(buffer, i + 1, new_str));
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	int			read_s;
	char		*new_str;

	read_s = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] == '\0')
	{
		read_s = read(fd, buffer, BUFFER_SIZE);
		if (read_s <= 0)
			return (NULL);
	}
	new_str = malloc(1);
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	return (ft_search_nl(fd, buffer, read_s, new_str));
}

/*
#include <stdio.h>
int	main(void)
{
int fd = open("1char.txt",O_RDONLY);
int fd3 = open("no_nl.txt",O_RDONLY);
int fd4 = open("nothing.txt", O_RDONLY);
int fd5 = open("thousand_nl.txt", O_RDONLY);
int i;
char *res;
	res = "yes";

	i = 1;
	while (res != NULL)
	{
		res = get_next_line(fd);
		printf("FD: %d - %d-Result:%s",fd ,i , res);
		if (res == NULL)
			printf("\n");
		free(res);
		i++;
	}
	printf("==================thousand_nl===================\n");
	res = "not_NULL";
	i = 1;
	while (res != NULL)
	{
		res = get_next_line(fd5);
		printf("FD: %d, %d - Result:%s",fd5, i, res);
		if (res == NULL)
			printf("\n");
		free(res);
		i++;
	}
	printf("=====================no_nl======================\n");
	res = get_next_line(fd3);
	printf("FD: %d - Result:%s",fd3, res);
	free(res);
	res = get_next_line(fd3);
	printf("FD: %d - Result:%s",fd3, res);
	free(res);
	printf("\n====================wrong_fd====================\n");
	res = get_next_line(1234);
	printf("FD: %d - Result:%s",1234 , res);
	free(res);
	printf("\n====================nothing=====================\n");
res = get_next_line(fd4);
printf("FD: %d - Result:%s",fd4 , res);
free(res);
}
*/