/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 01:33:20 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 01:35:54 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*res;

	if (s == NULL)
		return (NULL);
	res = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			res = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)res);
}
