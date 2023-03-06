/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:37:34 by etlim             #+#    #+#             */
/*   Updated: 2023/03/06 15:46:01 by etlim            ###   ########.fr       */
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
	while (!flag && (buffer[fd][0] || (read (fd, buffer, BUFFER_SIZE) > 0)))
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

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *res;

    fd = open("test.txt", O_RDONLY);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
	printf("ans - %d\n", res[0]);
	system ("leaks a.out");
    close(fd);
}

#include <fcntl.h>

int main()
{
    int fd;
    char *res;

    fd = open("test", O_RDWR);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    free(res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    free(res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    free(res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    free(res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    free(res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
    free(res);
    res = get_next_line(fd);
    printf("final = %s\n", res);
	printf("ans - %d\n", res[0]);
    free(res);
	system ("leaks a.out");
    close(fd);
}