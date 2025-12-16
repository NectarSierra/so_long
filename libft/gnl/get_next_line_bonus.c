/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:32:05 by nsaillez          #+#    #+#             */
/*   Updated: 2024/12/16 13:07:41 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	buffer[FD_MAX][BUFFER_SIZE];
	int			read_s;
	char		*new_str;

	read_s = 0;
	if ((fd < 0 || fd > FD_MAX) || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd][0] == '\0')
	{
		read_s = read(fd, buffer[fd], BUFFER_SIZE);
		if (read_s <= 0)
			return (NULL);
	}
	new_str = malloc(1);
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	return (ft_search_nl(fd, buffer[fd], read_s, new_str));
}

// #include <stdio.h>
// int	main(void)
// {
// 	int fd;
// 	char *res;
// 	int i;

// 	/*wrong fd*/
// 	fd = 123;
// 	res = get_next_line(fd);
// 	printf("===== wrong fd =====\n");
// 	printf("fd:%d, Line:%s",fd,res);

// 	/*1char.txt*/
//  	fd = open("../tester/1char.txt",O_RDONLY);
// 	res = get_next_line(fd);
// 	printf("\n\n===== 1char.txt =====\n");
// 	printf("fd:%d, Line:%s",fd,res);

// 	/*1line.txt*/
//  	fd = open("../tester/1line.txt",O_RDONLY);
// 	res = get_next_line(fd);
// 	printf("\n\n===== 1line.txt =====\n");
// 	printf("fd:%d, Line:%s",fd,res);

// 	/*50lines.txt*/
// 	printf("\n\n===== 50lines.txt =====\n");
// 	fd = open("../tester/50lines.txt",O_RDONLY);
// 	i = 1;
// 	while (res != NULL)
// 	{
// 		res = get_next_line(fd);
// 		if (res == NULL)
// 			printf("\n");
// 		printf("i:%d, fd:%d, Line:%s",i , fd,res);
// 		free(res);
// 		i++;
// 	}

// 	int fd1 = open("../tester/bonus-a.txt",O_RDONLY);
// 	int fd2 = open("../tester/bonus-b.txt",O_RDONLY);
// 	char *res1 = "";
// 	char *res2 = "";
// 	/*Bonus Test*/
// 	printf("\n\n===== Bonus.txt =====\n");
// 	i = 1;
// 	while (res1 != NULL && res2 != NULL)
// 	{
// 		res1 = get_next_line(fd1);
// 		if (res1 == NULL)
// 			printf("\n");
// 		printf("i:%d, fd:%d, Line:%s",i , fd1,res1);
// 		free(res1);
// 		res2 = get_next_line(fd2);
// 		if (res2 == NULL)
// 			printf("\n");
// 		printf("i:%d, fd:%d, Line:%s",i , fd2,res2);
// 		free(res2);
// 		i++;
// 	}

// 	free(res);
// }