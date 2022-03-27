/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:47:16 by sesim             #+#    #+#             */
/*   Updated: 2022/03/25 14:59:34 by seongmins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (cnt);
}

static char	**word_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

size_t	word_len(char const *s, char c)
{
	size_t	word_len;

	if (ft_strchr(s, c) == 0)
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

size_t	word_len_cnt(char const **s, char c)
{
	size_t	word_len;

	if (ft_strchr(*s, c) == 0)
		word_len = ft_strlen(*s);
	else
		word_len = ft_strchr(*s, c) - *s;
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	word_len;
	size_t	i;

	res = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (s == 0 || res == 0)
		return (word_free(res));
	i = 0;
	while (*s)
	{
		while (*s == c && s != 0)
			s++;
		if (*s != 0)
		{
			word_len = word_len_cnt(&s, c);
			res[i] = ft_substr(s, 0, word_len);
			if (res[i] == 0)
				return (word_free(res));
			s += word_len;
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
