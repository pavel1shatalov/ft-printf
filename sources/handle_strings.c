/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 21:35:48 by bsouchet          #+#    #+#             */
/*   Updated: 2019/04/14 15:56:26 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putstr(t_printf *p)
{
	unsigned	*s;
	int			len;

	if (!(s = va_arg(p->ap, unsigned*)))
	{
		if (!(p->f & F_ZERO))
			buffer(p, "(null)", 6);
		else
			while (p->min_length--)
				buffer(p, "0", 1);
	}
	else
	{
		len = (int)(ft_strlen((char*)s));
		(p->f & F_APP_PRECI) ? len = MIN(p->precision, len) : 0;
		p->padding = (p->min_length - len) > 0 ? (p->min_length - len) : 0;
		padding(p, 0);
		buffer(p, s, len);
		padding(p, 1);
	}
}

void	pf_character(t_printf *p, unsigned c)
{
	p->printed = 1;
	if ((p->padding = p->min_length - p->printed) < 0)
		p->padding = 0;
	padding(p, 0);
	buffer(p, c, p->printed);
	padding(p, 1);
}
