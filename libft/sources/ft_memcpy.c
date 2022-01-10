/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:09 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:10 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	int	i;

	i = 0;
	if (dest == 0 && src == 0)
	{
		return (NULL);
	}
	while (size--)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return ((char *)dest);
}
