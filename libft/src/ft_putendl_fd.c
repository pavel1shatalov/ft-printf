/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:42:42 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:42:42 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = -1;
	while (s[++i])
		write(fd, s + i, 1);
	write(fd, "\n", 1);
	return (i + 1);
}
