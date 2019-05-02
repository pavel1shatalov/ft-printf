/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:46:13 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:46:13 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	len = n < len ? n : len;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s1[i];
	return (res);
}
