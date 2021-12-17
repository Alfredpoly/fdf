/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:35 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:36 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1len;
	int		s2len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = ft_calloc((s1len + s2len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1len-- != 0)
	{
		ptr[i] = *s1++;
		i++;
	}
	while (s2len-- != 0)
	{
		ptr[i] = *s2++;
		i++;
	}
	return (ptr);
}
