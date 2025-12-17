/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:58:08 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/17 15:25:49 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**parsing(int fd);

static size_t	nb_split(char **tab)
{
	size_t	nb_split = 0;
	int		i = 0;
	int		j;

	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if ((tab[i][j] == 'S' || tab[i][j] == '|' ) && tab[i + 1] && tab[i+1][j] != '^')
				tab[i + 1][j] = '|';
			else if (tab[i][j] == '^' && tab[i - 1][j] == '|')
			{
				tab[i][j + 1] = '|';
				tab[i][j - 1] = '|';
				if (tab[i + 1] && tab[i + 1][j + 1] != '^')
					tab[i + 1][j + 1] = '|';
				if (tab[i + 1] && tab[i + 1][j - 1] != '^')
					tab[i + 1][j - 1] = '|';
				nb_split++;
			}
			j++;
		}
		i++;
	}
	return (nb_split);
}

int	main(void)
{
	int		fd = open("input", O_RDONLY);
	char	**tab = parsing(fd);
	int		i = 0;

	printf("%zu\n", nb_split(tab));
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	close(fd);
}
