/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:45:37 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:45:37 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;

	if (!s || !f)
		return (NULL);
	res = (char *)ft_strnew(ft_strlen(s));
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i])
		res[i] = (*f)(s[i]);
	return (res);
}
