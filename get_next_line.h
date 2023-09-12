/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:46:28 by claatkin          #+#    #+#             */
/*   Updated: 2023/09/12 18:59:10 by claatkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>

char	*fill_buffer(int fd, char *buffer);
char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*append_buffer(char **line, char *buffer);
char	*clear_buffer(char *buffer);
char	*move_buffer_to_next_line(int fd, char *buffer, char *buffer_start);
char	*buffer_init(int fd, char *buffer, char **buffer_start);
char	*get_next_line(int fd);

#endif