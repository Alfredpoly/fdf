/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:50:50 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:50:51 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	ch;

	s = (unsigned char *)str;
	ch = c;
	while ((s && n > 0) || (s == NULL))
	{
		if (*s == ch)
		{
			return ((void *)s);
		}
		s++;
		n--;
	}
	return (NULL);
}
