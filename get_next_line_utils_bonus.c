/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:01:15 by marvin            #+#    #+#             */
/*   Updated: 2023/04/29 17:01:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *strd)
{
	int	i;

	i = 0;
	if (!strd)
		return (0);
	while (strd[i] != '\0' && strd[i] != '\n')
		i++;
	if (strd[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	a;
	size_t	b;

	p = (char *) malloc ((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	a = 0;
	b = 0;
	while (s1 && s1[a])
		p[b++] = s1[a++];
	free(s1);
	a = 0;
	while (s2 && s2[a] && s2[a] != '\n')
		p[b++] = s2[a++];
	if (s2[a] == '\n')
		p[b++] = '\n';
	p[b] = '\0';
	return (p);
}

int	ft_zero(char *buf)
{
	int	l;
	int	h;
	int	valid;

	l = 0;
	h = 0;
	valid = 0;
	while (buf[l])
	{
		if (valid)
			buf[h++] = buf[l];
		if (buf[l] == '\n')
			valid = 1;
		buf[l++] = '\0';
	}
	return (valid);
}
