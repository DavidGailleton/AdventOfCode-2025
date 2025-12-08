/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 12:53:07 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/08 12:55:55 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include "get_next_char.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char	*get_highest_nbr(char *base, size_t remain, char *actual_best, char *result)
{
	// printf("Result = %s", result);
	if (remain == 0)
		return (result);
	if ((strlen(base)) <= remain)
		return (actual_best);
	if (base[0] > actual_best[0])
		actual_best = base;
	actual_best = get_highest_nbr(base + 1, remain, actual_best, result);
	// printf("%s\n", actual_best);
	if (actual_best == base)
		return (get_highest_nbr(base + 1, remain - 1, base + 1, ft_strjoin_new(result, actual_best, 0)));
	return (actual_best);
}

int	main(void)
{
	char		*temp;
	char		*highest_temp;
	int			fd;
	unsigned long long	result = 0;

	fd = open("input", O_RDONLY);
	temp = get_next_char(fd, '\n');
	while (temp)
	{
		printf ("Actual comb : %s", temp);
		highest_temp = get_highest_nbr(temp, 12, temp, ft_strdup(""));
		printf("highest Comb : %s\n\n", highest_temp);
		result += atoll(highest_temp);
		free(highest_temp);
		free(temp);
		temp = get_next_char(fd, '\n');
	}
	close(fd);
	printf("Result : %llu\n", result);
}
