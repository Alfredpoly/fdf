/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:11 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:12 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;
	char		*backd;
	const char	*backs;

	d = (char *)dest;
	s = (const char *)src;
	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	if (d < s)
	{
		while (size--)
			*d++ = *s++;
	}
	else
	{
		backd = d + (size - 1);
		backs = s + (size - 1);
		while (size--)
			*backd-- = *backs--;
	}	
	return (dest);
}
