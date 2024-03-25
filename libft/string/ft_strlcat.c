/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:43:43 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 01:42:09 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	dst_len;
	size_t	src_i;

	if (dst == NULL || src == NULL)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	dst_i = 0;
	while (dst[dst_i] != '\0' && dst_i < dstsize)
		dst_i++;
	if (dst[dst_i] != '\0')
		return (dst_i + ft_strlen(src));
	dst_len = dst_i;
	src_i = 0;
	while (dst_i < dstsize - 1 && src[src_i] != '\0')
		dst[dst_i++] = src[src_i++];
	dst[dst_i] = '\0';
	while (src[src_i] != '\0')
		src_i++;
	return (dst_len + src_i);
}
