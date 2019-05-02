/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:42:23 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:42:24 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_nextword(char const *s, char c)
{
	int	i;

	i = -1;
	if (!s || c == '\0')
		return (NULL);
	while (s[++i] && s[i] != c)
		;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (NULL);
	return ((char *)s + i);
}
