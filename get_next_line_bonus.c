/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:00:18 by marvin            #+#    #+#             */
/*   Updated: 2023/04/29 17:00:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// fopen_max n max de ficheiros que podem ser abertos em simultaneo

char	*get_next_line(int fd)
{
	static char		buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*str;
	int				i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
	{
		while (fd >= 0 && fd <= FOPEN_MAX && buff[fd][i])
			buff[fd][i++] = 0;
		return (NULL);
	}
	str = NULL;
	while (buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff[fd]);
		if (!str)
			return (NULL);
		if (ft_zero(buff[fd]) == 1)
			break ;
	}
	return (str);
}

/*
int main()
{
	char *line;
	char *line2;
	char *line3;
	int fd1;
	int fd2;
	int fd3;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	line = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

	printf("%s", line);
	printf("%s", line2);
	printf("%s", line3);

	free(line);
	free(line2);
	free(line3);
}
*/