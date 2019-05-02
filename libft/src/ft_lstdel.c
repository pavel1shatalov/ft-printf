/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:38:38 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:38:39 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*now;
	t_list	*tmp;

	if (!alst || !(*alst) || !del)
		return ;
	now = *alst;
	while (now)
	{
		tmp = now->next;
		ft_lstdelone(&now, del);
		now = tmp;
	}
	*alst = NULL;
}
