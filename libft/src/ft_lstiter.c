/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 21:39:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/05/02 21:39:16 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*now;
	t_list	*temp;

	if (!lst || !f)
		return ;
	now = lst;
	while (now)
	{
		temp = now->next;
		(*f)(now);
		now = temp;
	}
}
