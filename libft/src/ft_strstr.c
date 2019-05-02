/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:47:05 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:47:06 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			k = i;
			while (needle[++j] && haystack[++k] && haystack[k] == needle[j])
				;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
	}
	return (NULL);
}
