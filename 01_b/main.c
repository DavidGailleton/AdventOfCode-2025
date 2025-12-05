/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:00:08 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/05 12:37:42 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	turning_left(int nb, int temp, int *nb_zero)
{
	int	i = 0;

	while (temp > 0)
	{
		if (nb == 0 && temp > 0 && i > 0)
			(*nb_zero)++;
		if (nb == 0)
			nb = 99;
		else
			nb--;
		temp--;
		i++;
	}
	return (nb);
}

int	turning_right(int nb, int temp, int *nb_zero)
{
	while (temp > 0)
	{
		if (nb == 99 && temp > 1)
			(*nb_zero)++;
		if (nb == 99)
			nb = 0;
		else
			nb++;
		temp--;
	}
	return (nb);
}

int	main(void)
{
	char	*str;
	int		fd;
	int		nb = 50;
	int		temp;
	int		nb_zero = 0;

	fd = open("input", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		temp = atoi(&str[1]);
		if (str[0] == 'L')
			nb = turning_left(nb, temp, &nb_zero);
		if (str[0] == 'R')
			nb = turning_right(nb, temp, &nb_zero);
		if (nb == 0)
			nb_zero++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	printf("%d\n", nb_zero);
}
