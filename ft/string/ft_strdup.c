/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:18:26 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 13:21:57 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*p;

	if (s1 == NULL)
		return (NULL);
	size = ft_strlen(s1) + 1;
	p = malloc(size * sizeof(char));
	ft_memcpy(p, s1, size);
	return (p);
}
