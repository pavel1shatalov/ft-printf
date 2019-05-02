/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:47:35 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:47:36 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str, char del)
{
	int	i;
	int	wc;
	int	flag;

	if (!str || del == '\0')
		return (-1);
	i = -1;
	wc = 0;
	flag = 0;
	while (str[++i])
	{
		if (str[i] == del)
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			wc++;
		}
	}
	return (wc);
}
