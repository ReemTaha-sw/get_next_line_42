/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:49:46 by hankhali          #+#    #+#             */
/*   Updated: 2023/09/08 13:23:58 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

char	*read_line(int fd, char *str)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;

	bytes_read = 1;
	if (str == NULL)
		str = ft_strdup("");
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(str);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*skip_line(char *input_string)
{
	int		i;
	char	*remaining_string;

	i = 0;
	while (input_string[i] != '\0' && input_string[i] != '\n')
		i++;
	if (input_string[i] == '\0')
	{
		free(input_string);
		return (NULL);
	}
	remaining_string = ft_strdup(input_string + i + 1);
	free(input_string);
	return (remaining_string);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (buffer == NULL || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = skip_line(buffer);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("jj.txt", O_RDONLY);
	printf("\n\n=====  get next line one file  =====\n\n");
	i = 1;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("file :: line %d: ---------->  %s", i, line);
		i++;
	}
	printf("\n\n=====  colseing get next line  =====\n\n");
	close(fd);
	return (0);
}
// Main for user input :

// int main()
// {
//     char *line;

//     int i;
//     i = 0;

//     while(i < 1)
//     {
//         line = get_next_line(0);
//         if(line == NULL)
//             break;
//         printf("line: %s",line);
//         free(line);
//      i++;
//     }
//     return(0);
// }


// Main for bonus:


// int main(void)
// {
//     char    *line;
//     int     i;
//     int     fd1;
//     int     fd2;
//     int     fd3;

//     fd1 = open("jj.txt", O_RDONLY);
//     fd2 = open("jj1.txt", O_RDONLY);
//     fd3 = open("jj2.txt", O_RDONLY);
//     printf("\n\n=====  get next line from one file  =====\n\n");
//     i = 1;
//     while (i < 3)
//     {
//         line = get_next_line(fd1);
//         printf("line %d:            %s", i, line);
//         free(line);
//         line = get_next_line(fd2);
//         printf("line %d:            %s", i, line);
//         free(line);
//         line = get_next_line(fd3);
//         printf("line %d:            %s", i, line);
//         free(line);
//         i++;
//     }
//     printf("\n\n=====  colseing get next line with multibles files  =====\n\n");
//     close(fd1);
//     close(fd2);
//     close(fd3);
//     return (0);
// }


// Main for the normal get_next_line:

// int main(void)
// {
//     char    *line;
//     int     i;
//     int     fd;

//     fd = open("jj.txt", O_RDONLY);
//     printf("\n\n=====  get next line one file  =====\n\n");
//     i = 1;
//     while (i < 3)
//     {
//         line = get_next_line(fd);
//         printf("file :: line %d: ---------->  %s", i, line);
//         i++;
//     }
//     printf("\n\n=====  colseing get next line  =====\n\n");
//     close(fd);
//     return (0);
// }
