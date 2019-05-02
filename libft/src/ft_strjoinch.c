/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:45:13 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:45:14 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char **str, char c)
{
	char	*res;

	if (!str || !(*str))
		return (NULL);
	res = ft_strnew(ft_strlen(*str) + 1);
	if (!res)
		return (NULL);
	res = ft_strcpy(res, *str);
	res = ft_strncat(res, &c, 1);
	free(*str);
	*str = NULL;
	return (res);
}
