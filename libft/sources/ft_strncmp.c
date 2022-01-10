/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:49 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:50 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (*s1++ != *s2++)
			return ((*(unsigned char *)--s1) - (*(unsigned char *)--s2));
		else if (*s1 == '\0' && *s2 == '\0')
			break ;
	}
	return (0);
}
