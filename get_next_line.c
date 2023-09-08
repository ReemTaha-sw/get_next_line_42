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
	char	buffer[BUFFER_SIZE + 2];
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

// int	main(void)
// {
// 	int			fd;
// 	char	*str;
// 	fd = open("jj.txt", O_RDONLY);
// 	// printf("%s\n",get_next_line(fd));
// 	// printf("%s\n",get_next_line(fd));
// 	// printf("%s\n",get_next_line(fd));
// 	// printf("%s\n",get_next_line(fd));
	
//     // while (res)
//     // {
// 	// 	printf("%s", res);
// 	// 	free(res);
// 	// 	res = get_next_line(fd);

//     // }
// 	close (fd);
// 	// res = get_next_line(fd);
// }

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int         fd;

//     fd = open("txt1.txt", O_RDONLY);
//     char        *res = NULL;
//     size_t      chars_read;
//     size_t      total_chars_read = 0;
//     size_t      max_chars_to_read = BUFFER_SIZE; // Adjust as needed
//     while (total_chars_read < max_chars_to_read && (res = get_next_line(fd)))
//     {
//         chars_read = strlen(res);
//         total_chars_read += chars_read;

//         if (total_chars_read > max_chars_to_read)
//         {
//             // Trim excess characters
//             size_t trim_chars = total_chars_read - max_chars_to_read;
//             res[chars_read - trim_chars] = '\0';
//             printf("%s", res);
//             free(res);
//             break;
//         }
//         printf("%s", res);
//         free(res);
//     }
//     close(fd);
//     return (0);
// }