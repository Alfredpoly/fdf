/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:55 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:56 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	int		k;

	if (!s1)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s1);
	while (charset(s1[i], (char *)set) == 1)
		i++;
	while ((charset(s1[j - 1], (char *)set) == 1) && s1[i] != '\0')
		j--;
	if (i == ft_strlen(s1))
	{
		j = 0;
		i = 0;
	}
	ptr = ft_calloc((j - i + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (i != j)
		ptr[k++] = s1[i++];
	return (ptr);
}
