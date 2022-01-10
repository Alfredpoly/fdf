/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:39 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:40 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	int		i;

	srclen = 0;
	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && dstsize > 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		dst[i] = '\0';
	}
	while (src[srclen] != '\0')
	{
		srclen++;
	}
	return (srclen);
}
