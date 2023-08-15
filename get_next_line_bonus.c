/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:37:34 by etlim             #+#    #+#             */
/*   Updated: 2023/05/02 19:21:33 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[4096][BUFFER_SIZE + 1];
	char		*line;
	int			a;
	int			b;
	int			flag;

	if (BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read (fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer[fd]);
		a = 0;
		b = 0;
		while (buffer[fd][a])
		{
			if (flag)
				buffer[fd][b++] = buffer[fd][a];
			if (buffer[fd][a] == '\n')
				flag = 1;
			buffer[fd][a++] = 0;
		}
	}
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	static int	fd;
// 	static int	fd2;
// 	int	i = 0;

//     fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Failed to open & read file.\n");
//         return (1);
//     }
// 	while (i++ < 6)
// 	{
// 		printf("main: [%s]\n", get_next_line(fd));
// 		printf("main: [%s]\n", get_next_line(fd2));
// 	}
// }

// int main()
// {
// 	int fd;
// 	char *res;
// 	int fd1;
// 	char *res2;

//     fd = open("test.txt", O_RDWR);
//     res = get_next_line(fd);
// 	fd1 = open("test2.txt", O_RDWR);
// 	res2 = get_next_line(fd1);
//     printf("final = %s\n", res);
// 	free(res);
//     // res = get_next_line(fd1);
//     // printf("final = %s\n", res2);
// 	// free(res2);
//     res = get_next_line(fd);
//     printf("final = %s\n", res);
// 	free(res);
//     // res2 = get_next_line(fd1);
//     // printf("final = %s\n", res2);
// 	// free(res2);
//     res = get_next_line(fd);
//     printf("final = %s\n", res);
// 	free(res);
//     // res2 = get_next_line(fd1);
//     // printf("final = %s\n", res2);
//     res = get_next_line(fd);
//     printf("final = %s\n", res);
// 	printf("ans - %d\n", res[0]);
// 	system ("leaks a.out");
//     close(fd);
// }