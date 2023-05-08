/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:07:36 by marvin            #+#    #+#             */
/*   Updated: 2023/04/29 15:07:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (buff[i])
			buff[i++] = '\0';
		return (NULL);
	}
	str = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
		if (ft_zero(buff) == 1)
			break ;
	}
	return (str);
}

/*
int main(void)
{
	int	fd;
	char	*line;

    fd = open("fd.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	printf("\n");
	close(fd);
	return (0);
}
*/