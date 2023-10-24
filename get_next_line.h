/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:46:28 by claatkin          #+#    #+#             */
/*   Updated: 2023/10/24 12:29:45 by claatkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Define la interfaz para las funciones utilizadas en get_next_line.c. */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*fill_buffer(int fd, char *buffer);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*append_buffer(char *line, char *buffer);
char	*clear_buffer(char *buffer);
char	*move_buffer_to_next_line(char *buffer);
char	*buffer_init(int fd, char *buffer);
char	*get_next_line(int fd);

#endif