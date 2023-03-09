/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:59:46 by chmassa           #+#    #+#             */
/*   Updated: 2022/12/13 10:32:34 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *s1, char *s2, int fr)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if ((!s1) || (!s2))
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (fr == 1)
		free(s1);
	return (str);
}

static void	ft_cut_after_nl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		if (s[i] == '\n')
			s[i +1] = '\0';
		i++;
	}
}

static void	ft_read(char **s, char *saved, int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];

	size = 1;
	buf[0] = '\0';
	if (saved)
		*s = ft_join(*s, saved, 0);
	while (size != 0 && !ft_strchr(buf, '\n'))
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		*s = ft_join(*s, buf, 1);
	}
	if (size != 0 && *buf)
	{
		ft_strcpy(saved, ft_strchr(buf, '\n') + 1);
		ft_cut_after_nl(*s);
	}
	if (!ft_strchr(*s, '\n'))
		*saved = 0;
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	saved[1024][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	s = "";
	if (*saved && ft_strchr(saved[fd], '\n'))
	{
		s = ft_join(s, saved[fd], 0);
		ft_cut_after_nl(s);
		ft_strcpy(saved[fd], ft_strchr(saved[fd], '\n' ) + 1);
	}
	else
	{
		ft_read(&s, saved[fd], fd);
		if (ft_strlen(s) == 0)
		{
			free(s);
			return (NULL);
		}
	}
	return (s);
}
