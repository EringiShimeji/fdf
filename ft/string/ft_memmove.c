/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:24:07 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 02:08:30 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;

	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	if (dst == NULL || src == NULL)
		return (NULL);
	dst_p = dst;
	src_p = src;
	while (len > 0)
	{
		len--;
		dst_p[len] = src_p[len];
	}
	return (dst);
}
