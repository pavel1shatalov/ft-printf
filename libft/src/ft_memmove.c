/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:41:37 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:41:38 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	const char	*nsrc;
	size_t		i;

	ndst = dst;
	nsrc = src;
	i = -1;
	if (ndst > nsrc)
		while (len > 0)
		{
			--len;
			ndst[len] = nsrc[len];
		}
	else if (ndst < nsrc)
		while (++i < len)
			ndst[i] = nsrc[i];
	return (dst);
}
