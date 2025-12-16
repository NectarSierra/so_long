/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaillez <nsaillez@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 08:28:20 by nsaillez          #+#    #+#             */
/*   Updated: 2024/12/16 13:06:22 by nsaillez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# if BUFFER_SIZE > 1000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	clear_buffer(char *buffer);
char	*free_null(char *new_str);
char	*ft_declare_res(char *str1, char *str2, int length);
char	*ft_join(char *str1, char *str2, int length);
char	*ft_trim_front(char *str, int length, char *new_str);
char	*ft_search_nl(int fd, char *buffer, int read_s, char *new_str);
char	*get_next_line(int fd);

#endif
