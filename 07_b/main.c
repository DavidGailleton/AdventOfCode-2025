/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:58:08 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/17 17:35:52 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**parsing(size_t fd);

#define SIZE 142

static void	fill_line(char **tab, size_t int_tab[SIZE][SIZE], size_t i)
{
	int	j = 0;

	while (tab[i][j])
	{
		if (tab[i][j] == '|')
			int_tab[i][j] = int_tab[i + 1][j];
		j++;
	}
	j = 0;
	while (tab[i][j])
	{
		if (tab[i][j] == '^')
			int_tab[i][j] = int_tab[i][j + 1] + int_tab[i][j - 1];
		j++;
	}

	printf(tab[i]);
	for (int j = 0 ; j < SIZE  ; j++) {
		printf("%.1zu|", int_tab[i][j]);
	}
	printf("\n");

}

void print_int_tab(size_t int_tab[SIZE][SIZE]) {
	for (int i = 0 ; i < SIZE  ; i++) {
		for (int j = 0 ; j < SIZE  ; j++) {
			printf("%.1zu|", int_tab[i][j]);
		}
		printf("\n");
	}
}

static void	nb_timeline(char **tab, size_t int_tab[SIZE][SIZE])
{
	int	j = 0;

	while (tab[SIZE - 1][j])
	{
		if (tab[SIZE - 1][j] == '|')
			int_tab[SIZE - 1][j] = 1;
		else
			int_tab[SIZE - 1][j] = 0;
		j++;
	}
	j = SIZE - 2;
	while (j > 0)
	{
		fill_line(tab, int_tab, j--);
	}
	print_int_tab(int_tab);
	printf("%zu\n", int_tab[1][SIZE / 2]);
}

static void	write_paths(char **tab)
{
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
			}
			j++;
		}
		i++;
	}
}

static void	print_tab(char **tab)
{
	int	i = 0;

	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}

int	main(void)
{
	int		fd = open("input", O_RDONLY);
	char	**tab = parsing(fd);
	int		i = 0;
	static size_t	int_tab[SIZE][SIZE];
	print_int_tab(int_tab);

	write_paths(tab);
	print_tab(tab);
	while (tab[0][i] != 'S')
		i++;
	nb_timeline(tab, &int_tab);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	close(fd);
}
