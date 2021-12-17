/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:51:25 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:51:26 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**clear(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

int	countstr(char const *s, char c)
{
	int	i;
	int	nbstr;

	i = 0;
	nbstr = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
		nbstr++;
	}
	return (nbstr);
}

int	countchar(char const *s, int i, char c)
{
	int	nbchar;

	nbchar = 0;
	while (s[i] != c && s[i] != '\0')
	{
		nbchar++;
		i++;
	}
	return (nbchar);
}

char	**createarr(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	arr = ft_calloc((countstr(s, c) + 1), sizeof(char *));
	if (!arr)
		return (0);
	while (s[i] != '\0')
	{
		k = 0;
		arr[j] = ft_calloc((countchar(s, i, c) + 1), sizeof(char));
		if (!arr[j])
			return (clear(arr));
		while (s[i] != c && s[i] != '\0')
			arr[j][k++] = s[i++];
		while (s[i] == c && s[i] != '\0')
			i++;
		j++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	s = ft_strtrim(s, &c);
	if (!s)
		return (0);
	arr = createarr(s, c);
	free((void *)s);
	return (arr);
}
