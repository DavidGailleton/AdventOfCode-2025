/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:31:43 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/15 16:05:55 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_char.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

static char	**parsing(void)
{
	int		fd = open("input", O_RDONLY);
	char	*temp = get_next_char(fd, '\n');
	char	*new;
	char	*str = NULL;
	char	**wall;

	while (temp)
	{
		if (!str)
			new = ft_strdup(temp);
		else
		{
			new = ft_strjoin(str, temp);
			free(str);
		}
		free(temp);
		str = new;
		temp = get_next_char(fd, '\n');
	}
	wall = ft_split(str, '\n');
	return (free(str), wall);
}

static int	is_roll(char **wall, int i, int j)
{
	if (wall[i][j] == '@')
		return (1);
	return (0);
}

static int	roll_arround(char **wall, int i, int j)
{
	int	rolls = 0;
	int	k = -1;

	while (k <= 1)
	{
		if (i + k >= 0 && wall[i + k])
		{
			if (j > 0)
				rolls += is_roll(wall, i + k, j - 1);
			if (k)
				rolls += is_roll(wall, i + k, j);
			rolls += is_roll(wall, i + k, j + 1);
		}
		k++;
	}
	return (rolls);
}

int	main(void)
{
	char	**wall = parsing();
	int		nb_fl = 0;
	int		temp;
	int		i = 0;
	int		j;

	while (wall[i])
	{
		j = 0;
		while (wall[i][j])
		{
			if (is_roll(wall, i, j))
			{
				temp = roll_arround(wall, i, j);
				if (temp < 4)
					nb_fl++;
			}
			j++;
		}
		i++;
	}
	i = -1;
	while (wall[++i])
		free(wall[i]);
	free(wall);
	printf("%d\n", nb_fl);
}
