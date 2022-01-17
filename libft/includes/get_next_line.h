/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/17 10:46:48 by fpolycar      #+#    #+#                 */
/*   Updated: 2022/01/17 10:46:49 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
size_t	ft_strlen_next(const char *str);
int		stop_newline(char *str);
char	*ft_strjoin_next(char const *s1, char const *s2);
char	*ft_strdup_next(const char *s1);
char	*ft_substr_next(char const *s, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

#  ifndef OPEN_MAX
#   define OPEN_MAX 42

#  endif
# endif
#endif