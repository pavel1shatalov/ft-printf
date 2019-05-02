/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:41:47 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:41:48 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*now;
	int		i;

	if (len == 0)
		return (b);
	now = (char *)b;
	i = -1;
	while (++i < (int)len)
		now[i] = c;
	return (b);
}
