/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmassa <chrisdev427@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:22:30 by chmassa           #+#    #+#             */
/*   Updated: 2022/11/17 09:35:02 by chmassa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	if (((!dst) || (!src)) && (dstsize == 0))
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = 0;
	i = dst_len;
	if (dstsize == 0)
		return (src_len);
	if (dstsize < dst_len)
		return (src_len + dstsize);
	while (i < (dstsize -1) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_len + src_len);
}
