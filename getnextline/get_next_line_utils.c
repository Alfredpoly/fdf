#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	stop_newline(char *str)
{
	int	l;

	l = 0;
	while (str[l])
	{
		if (str[l] == '\n')
			return (l);
		l++;
	}
	return (-1);
}

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
	ptr = malloc((s1len + s2len + 1) * sizeof(char));
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
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1[j] != '\0')
	{
		ptr[j] = s1[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (start < ft_strlen(s) && len > 0)
	{
		ptr[i] = s[start];
		start++;
		len--;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
