/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aoc02.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:22:54 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/05 16:14:53 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOC02_H
# define AOC02_H

# include <stdlib.h>

typedef struct s_comb
{
	long long	first;
	long long	second;
	long long	*invalids;
	int			nb_invalid;
	struct s_comb		*next;
}	t_comb;

t_comb	*ft_parsing(int fd);

#endif
