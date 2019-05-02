/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:46:27 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:46:28 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	check;

	check = 0;
	if (size == check - 1)
		return (NULL);
	res = ft_memalloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	return (res);
}
