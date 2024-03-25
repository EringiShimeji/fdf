/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:08:25 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 22:26:24 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	word_cnt;

	word_cnt = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			word_cnt++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (word_cnt);
}

char	*get_word(char const **ptr, char c)
{
	size_t		word_len;
	char const	*s;
	char		*res;

	s = *ptr;
	word_len = 0;
	while (*s == c)
		s++;
	while (s[word_len] != '\0' && s[word_len] != c)
		word_len++;
	res = malloc((word_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s, word_len);
	res[word_len] = '\0';
	*ptr = s + word_len;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_cnt;
	char	**res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	word_cnt = count_words(s, c);
	res = malloc((word_cnt + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < word_cnt)
	{
		res[i] = get_word(&s, c);
		if (res[i] == NULL)
		{
			while (i-- > 0)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
