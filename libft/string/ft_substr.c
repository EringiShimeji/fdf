/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:24:22 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 17:29:32 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;
	size_t	cpy_len;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	cpy_len = 0;
	while (cpy_len < len && s[cpy_len + start] != '\0')
		cpy_len++;
	cpy = malloc((cpy_len + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	s += start;
	while (i < cpy_len && s[i] != '\0')
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
