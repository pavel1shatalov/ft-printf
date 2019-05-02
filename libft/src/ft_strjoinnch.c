/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinnch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:45:20 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:45:20 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinnch(char *str, char c, int n)
{
	int		i;
	char	*res;

	if (n <= 0)
		return (ft_strdup(str));
	res = ft_strnew(ft_strlen(str) + n);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	while (n--)
		res[i++] = c;
	return (res);
}
