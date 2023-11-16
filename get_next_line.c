/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:36:42 by claatkin          #+#    #+#             */
/*   Updated: 2023/11/15 19:03:38 by claatkin         ###   ########.fr       */
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
	else
		line = malloc(1);
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
char	*move_buffer_to_next_line(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		j = 0;
		while (buffer[i] != '\0')
		{
			buffer[j] = buffer[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
	}
	else
		buffer[0] = '\0';
	return (buffer);
}

/* inicializa el buffer */
char	*buffer_init(int fd, char *buffer)
{
	if (fd < 0 || fd > 511 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= 511)
		{
			buffer = clear_buffer(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (!buffer)
	{
		buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
		if (!buffer)
			return (NULL);
		*buffer = '\0';
	}
	return (buffer);
}

/* es la función principal que lee líneas desde el descriptor de archivo */
/*char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	buffer = buffer_init(fd, buffer);
	if (!buffer)
		return (NULL);
	while (!line || !(ft_strchr(line, '\n')))
	{
		if (*buffer == '\0')
			buffer = fill_buffer(fd, buffer);
		else
			return (NULL);
		line = append_buffer(line, buffer);
		buffer = move_buffer_to_next_line(buffer);
		return (line);
	}
	return (line);
}*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	buffer = buffer_init(fd, buffer);
	if (!buffer)
		return (NULL);
	while (!line || !(ft_strchr(line, '\n')))
	{
		if (*buffer == '\0')
			buffer = fill_buffer(fd, buffer);
		if (!buffer)
			return (NULL);
		line = append_buffer(line, buffer);
		buffer = move_buffer_to_next_line(buffer);
		if (line && ft_strchr(line, '\n'))
			break ;
		return (line);
	}
	if (!line)
		return (NULL);
	return (line);
}

/*#include <stdio.h>
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
	close(n);
}*/
