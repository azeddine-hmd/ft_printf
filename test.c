#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}

int		ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub_str;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		len = 0;
	if (!(sub_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	while (i < (start + len))
	{
		sub_str[i - start] = s[i];
		i++;
	}
	sub_str[i - start] = '\0';
	return (sub_str);
}

int		ft_get_precision(char *s, int start, char **precision)
{
	int		i;
	int		len;

	if (s[start] == '.' && s[start + 1] == '*')
	{
		if (!(*precision = ft_substr(s, start, 2)))
			return (-1);
		return (start + 2);
	}
	else if (s[start] == '.' && s[start + 1] != '*')
	{
		i = start;
		len = 1;
		while (ft_isdigit(s[++i]))
			len++;
		if (!(*precision = ft_substr(s, start, len)))
			return (-1);
		printf("len = %d\n", len);
		return (len + start);
	}
	return (start);
}

int		main(void)
{
	char	*s = strdup("welcome%.sdsdasd");
	int		start = 8;
	char	*precision;
	int		re;

	precision = NULL;
	re = ft_get_precision(s, start, &precision);
	printf("%s\n", precision);
	printf("\nreturn = %d\n", re);
	return (0);
}
