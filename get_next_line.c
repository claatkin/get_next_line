/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claatkin <claatkin@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:36:42 by claatkin          #+#    #+#             */
/*   Updated: 2023/07/21 13:32:03 by claatkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_buffer(int fd, char *buffer)
{
	int	intiewinkie;

	intiewinkie = read(fd, buffer, BUFFER_SIZE);
	return (intiewinkie);
}

static char	*append_buffer(char **line, char *buffer)
{
	int		i;
	int		line_length;
	char	*aux;

	i = 0;
	line_length = 0;
	if (*line)
		line_length = ft_strlen(*line);
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (*(buffer + i) == '\n')
		i++;
	if (i == 0)
		return (NULL);
	*aux = *line;
	*line = ft_strjoin(*line, *buffer);
	*line = *aux;
}

static char	*clear_buffer(char *buffer)
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
		free (buffer);
	}
	return (NULL);
}

static char	*move_buffer_to_next_line(int fd, char *buffer, char *buffer_start)
{
	int	buffer_length;
	
	if (*buffer == '\0')
	{
		
	}
	// Una vez hayas pegado la parte del buffer que llega hasta \n, dentro del buffer tiene que quedar lo que pueda hacer falta para la siguiente línea Entones moveria todo lo que haya SI EXISTE detras de un \n al principio del buffer
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (buffer == NULL)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
	}
	while (!line || !(ft_strchr(line, '\n')))
	{
		if (*buffer == '\0')
			fill_buffer(fd, buffer);
		append_buffer();
		move_buffer_to_next_line();
	}
	return (line);
}

int main(void)
{
	int n;
	char *buff;
	char path[] = "claudia.txt";
	
	n = open(path, O_RDONLY);
	buff = get_next_line(n);
	printf("\n\n%s\n\n,buff");
}
