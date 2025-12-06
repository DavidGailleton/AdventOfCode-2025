/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:39:53 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/06 20:42:04 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "aoc02.h"
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

static int	check_if_invalid(long long nb)
{
	char	*str;
	char	*temp;
	size_t	len;
	size_t	i = 1;
	size_t	j;

	str = ft_lltoa(nb);
	//printf("%s\n", str);
	if (!str)
		return (0);
	len = strlen(str);
	while (i <= (len / 2))
	{
		if (!(len % i))
		{
			j = 1;
			temp = ft_substr(str, 0, i);
			while (len > i * j)
			{
				if (ft_strncmp(temp, &str[i * j], i))
				{
					if (i * j >= len)
					{
						printf("%lld\n", nb);
						return (1);
					}
					else
						break ;
				}
				j++;
			}
			free(temp);
		}
		i++;
	}
	free(str);
	return (0);
}

static long long	*add_invalid(t_comb *comb, long long invalid)
{
	long long	*temp;
	int			i = 0;

	temp = malloc(sizeof(long long) * (comb->nb_invalid + 1));
	if (!temp)
		return (NULL);
	while (i < comb->nb_invalid)
	{
		temp[i] = comb->invalids[i];
		i++;
	}
	temp[i] = invalid;
	free(comb->invalids);
	comb->nb_invalid++;
	return (temp);
}

static void	get_invalids(t_comb *comb)
{
	long long	actual;

	actual = comb->first;
	while (actual <= comb->second)
	{
		if (check_if_invalid(actual))
		{
			comb->invalids = add_invalid(comb, actual);
			if (!comb->invalids)
				return ;
		}
		actual++;
	}
}

static void	clear_lst(t_comb *lst)
{
	t_comb	*temp;

	while (lst)
	{
		temp = lst->next;
		if (lst->invalids)
			free(lst->invalids);
		free(lst);
		lst = temp->next;
	}
}

//8175253565 -> too low
//24157613387
int	main(void)
{
	t_comb	*lst;
	t_comb	*temp;
	int		fd;
	int		i;
	unsigned long long	result = 0;

	fd = open("input", O_RDONLY);
	lst = ft_parsing(fd);
	temp = lst;
	while (temp)
	{
		//printf("%lld - %lld\n", temp->first, temp->second);
		get_invalids(temp);
		temp = temp->next;
	}
	temp = lst;
	while (temp)
	{
		i = 0;
		//printf("result = %lld", result);
		while (i < temp->nb_invalid)
		{
			result += temp->invalids[i];
			i++;
		}
		temp = temp->next;
	}
	printf("%llu", result);
	clear_lst(lst);
	close(fd);
}

//iterer sur chaque node
	//applique une fonction
		//incrmeenter le retour de fonction dans res
//
//return res 
