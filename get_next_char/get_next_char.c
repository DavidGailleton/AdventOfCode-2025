/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:20:41 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/05 14:04:02 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_char.h"
#include <unistd.h>

static int	del_before_char(char buf[BUFFER_SIZE], char c)
{
	int		nl_i;
	int		i;
	char	*temp;

	nl_i = index_of_char(buf, BUFFER_SIZE, c);
	if (nl_i >= 0)
	{
		temp = ft_substr(buf, nl_i + 1, BUFFER_SIZE - nl_i);
		if (!temp)
			return (-1);
		ft_bzero(buf, BUFFER_SIZE);
		i = 0;
		while (temp[i])
		{
			buf[i] = temp[i];
			i++;
		}
		free(temp);
	}
	return (1);
}

static char	*ft_read_one(char buf[BUFFER_SIZE], int fd, char *str)
{
	int	temp;

	str = ft_strjoin_new(str, buf, BUFFER_SIZE);
	if (!str)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE);
	temp = read(fd, buf, BUFFER_SIZE);
	if (temp < 0)
	{
		free(str);
		return (NULL);
	}
	if ((!str || ft_strlen(str) == 0) && temp == 0)
	{
		free(str);
		return (NULL);
	}
	if (temp == 0)
		return (str);
	return (str);
}

static char	*extract_all_char(char buf[BUFFER_SIZE], int fd, char *str, int nl_i, char c)
{
	int	temp;

	if (!str)
		return (NULL);
	while (nl_i < 0)
	{
		str = ft_read_one(buf, fd, str);
		if (!str)
			return (NULL);
		nl_i = index_of_char(buf, BUFFER_SIZE, c);
		if (nl_i < 0 && !ft_strlen(buf))
			return (str);
	}
	str = ft_strjoin_new(str, buf, nl_i);
	if (!str)
		return (NULL);
	temp = del_before_char(buf, c);
	if (temp < 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_char(int fd, char c)
{
	static char	buf[BUFFER_SIZE + 1];
	int			nl_i;
	int			temp;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nl_i = index_of_char(buf, BUFFER_SIZE, c);
	if (nl_i >= 0)
	{
		str = ft_substr(buf, 0, nl_i + 1);
		temp = del_before_char(buf, c);
		if (temp < 0)
			return (free(str), NULL);
	}
	else
		str = extract_all_char(buf, fd, ft_substr("", 0, 1), nl_i, c);
	return (str);
}
