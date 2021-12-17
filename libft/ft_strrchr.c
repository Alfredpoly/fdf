/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:53 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:54 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	first;

	ch = c;
	first = *str;
	while (*str != '\0')
		str++;
	while (*str != ch)
	{
		if (*str == first)
			return (NULL);
		str--;
	}
	return ((char *)str);
}
