/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:06 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:07 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return ((*(unsigned char *)--s1) - (*(unsigned char *)--s2));
	}
	return (0);
}
