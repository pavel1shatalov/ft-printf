/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:40:43 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:40:44 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ndst;
	unsigned const char	*nsrc;
	size_t				i;

	ndst = (unsigned char *)dst;
	nsrc = (unsigned const char *)src;
	i = -1;
	while (++i < n)
	{
		ndst[i] = nsrc[i];
		if (ndst[i] == (unsigned char)c)
			return (ndst + i + 1);
	}
	return (NULL);
}
