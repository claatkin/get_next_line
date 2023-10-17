/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:36:42 by claatkin          #+#    #+#             */
/*   Updated: 2023/10/17 17:21:20 by claatkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* agrega datos del buffer a la line */
char	*append_buffer(char *line, char *buffer)
{
	int		i;
	int		line_length;
	char	*aux;

	i = 0;
	line_length = 0;
	if (line)
		line_length = ft_strlen(line);
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (*(buffer + i) == '\n')
		i++;
	if (i == 0)
		return (NULL);
	aux = line;
	line = ft_strjoin(line, buffer);
	free(aux);
	aux = line;
	line = ft_substr(line, 0, line_length + i);
	free(aux);
	return (line);
}

/*  limpia el buffer */
char	*clear_buffer(char *buffer)
{
	int	i;

	if (buffer)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
		free(buffer);
	}
	return (NULL);
}

/* mueve el buffer a la siguiente línea */
char	*move_buffer_to_next_line(char *buffer, char *buffer_start)
{
	while (*buffer != '\n' && *buffer != '\0')
		buffer++;
	if (*buffer == '\n')
		buffer++;
	else
	{
		buffer = buffer_start;
		*buffer = '\0';
	}
	return (buffer);
}

/* inicializa el buffer */
char	*buffer_init(int fd, char *buffer, char **buffer_start)
{
	if (fd < 0 || fd > 511 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= 511)
		{
			buffer = clear_buffer(*buffer_start);
			*buffer_start = NULL;
		}
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (!buffer)
			return (NULL);
		*buffer = '\0';
		*buffer_start = buffer;
	}
	return (buffer);
}

/* es la función principal que lee líneas desde el descriptor de archivo */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	static char	*buffer_start;

	line = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer = buffer_init(fd, buffer, &buffer_start);
	if (!buffer)
		return (NULL);
	while (!line || !(ft_strchr(line, '\n')))
	{
		if (*buffer == '\0')
		{
			fill_buffer(fd, buffer, buffer_start);
			if (line && *line == '\0')
			{
				free(line);
				line = NULL;
			}
		}
		else
			return (NULL);
		line = append_buffer(line, buffer);
		move_buffer_to_next_line(buffer, buffer_start);
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int n;
	char *buff;
	char path[] = "claudia.txt";

	n = open(path, O_RDONLY);
	buff = (char *) - 1;
	while (buff)
	{
		buff = get_next_line(n);
		printf("\n\n%s\n\n", buff);
	}
}
