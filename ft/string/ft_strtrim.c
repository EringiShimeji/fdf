/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:39:01 by smatsuo           #+#    #+#             */
/*   Updated: 2023/09/05 23:10:03 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	begin = 0;
	while (ft_strchr(set, s1[begin]) != NULL)
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_strrchr(set, s1[end - 1]) != NULL)
		end--;
	return (ft_substr(s1, begin, end - begin));
}
