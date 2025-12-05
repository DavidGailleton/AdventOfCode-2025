/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_char.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:22:03 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/05 16:18:29 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_CHAR_H
# define GET_NEXT_CHAR_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include "libft.h"

char	*get_next_char(int fd, char c);

char	*ft_strjoin_new(char const *s1, char const *s2, size_t limit);
int		index_of_char(char *str, int limit, char c);

#endif
