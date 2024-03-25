/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 02:21:52 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 02:38:54 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hi;
	size_t	ni;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	hi = 0;
	while (haystack[hi] != '\0' && hi < len)
	{
		ni = 0;
		while (needle[ni] != '\0' && hi + ni < len
			&& haystack[hi + ni] == needle[ni])
			ni++;
		if (needle[ni] == '\0')
			return ((char *)haystack + hi);
		hi++;
	}
	return (NULL);
}
