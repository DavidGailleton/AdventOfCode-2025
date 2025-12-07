/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:53:07 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/07 17:43:45 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "get_next_char.h"
#include <fcntl.h>
#include <unistd.h>

// to low 11928
// to low 16427
// To low 16449

int	main(void)
{
	char		*temp;
	int			fd;
	char		*first = NULL;
	char		*second = NULL;
	int			i;
	long long	result = 0;

	fd = open("input", O_RDONLY);
	temp = get_next_char(fd, '\n');
	while (temp)
	{
		printf ("Actual comb : %s\n", temp);
		i = 0;
		first = temp;
		while (temp[i + 2])
		{
			if ((temp[i] - '0') > (first[0] - '0'))
				first = &temp[i];
			i++;
		}
		i = 1;
		second = first + 1;
		while (first[i + 1])
		{
			if ((first[i] - '0') > (second[i] - '0'))
				second = &first[i];
			i++;
		}
		printf("Best comb = %c%c\n\n", first[0], second[0]);
		result += (first[0] - '0') * 10;
		result += second[0] - '0';
		free(temp);
		temp = get_next_char(fd, '\n');
	}
	close(fd);
	printf("%lld\n", result);
}
