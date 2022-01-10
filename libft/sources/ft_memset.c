/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:14 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:15 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t nb)
{
	unsigned char	*trs;

	trs = (unsigned char *)str;
	while (nb > 0)
	{
		*trs++ = c;
		nb--;
	}
	return (str);
}
