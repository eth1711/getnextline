/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:37:34 by etlim             #+#    #+#             */
/*   Updated: 2023/03/06 15:31:37 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			a;
	int			b;
	int			flag;

	if (BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read (fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		a = 0;
		b = 0;
		while (buffer[a])
		{
			if (flag)
				buffer[b++] = buffer[a];
			if (buffer[a] == '\n')
				flag = 1;
			buffer[a++] = 0;
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
