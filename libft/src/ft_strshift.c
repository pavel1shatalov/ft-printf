/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:46:50 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:46:51 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char **str, size_t n)
{
	char	*res;

	if (!str || !(*str))
		return (NULL);
	res = ft_strsub(*str, n, ft_strlen(*str) - n);
	if (!res)
		return (NULL);
	free(*str);
	*str = NULL;
	return (res);
}
