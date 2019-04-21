/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:59:30 by ggerhold          #+#    #+#             */
/*   Updated: 2019/04/21 22:06:00 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ldtoa_fill(double n, t_printf *p, long value)
{
	int		len;
	int		accuracy;
	char	s[48]; // why 48?

	len = p->printed - 1 - p->precision;
	accuracy = p->printed - 1 - len;
	while (accuracy--)
	{
		s[len + accuracy + 1] = value % 10 + '0';
		value /= 10;
	}
	(p->precision > 0) ? s[len] = '.' : 0;
	value = (long)(DABS(n));
	while (++accuracy < len)
	{
		s[len - accuracy - 1] = value % 10 + '0'; //starts from len-1
		value /= 10;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0; // aka undefined behaviour
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, len + 1 + p->precision);
}

void			pf_putdouble(t_printf *p)
{
	double		n;
	long		tmp;
	int			len;
	double		decimal;
	long		value;

	n = (double)va_arg(p->ap, double); // try without cast
	(p->f & F_ZERO) ? p->precision = p->min_length : 0; // number includes zeros; precision - only after point ?
	if (!(p->f & F_APP_PRECI))
		p->precision = 6; // default value
	len = (p->precision > 0) ? 1 : 0; // len includes point
	tmp = (long)(DABS(n)); // DABS?
	while (tmp && ++len)
		tmp /= 10;
	(p->f & F_ZERO) ? p->precision = p->min_length : 0; // delete?!
	p->printed = p->precision + len + ((n < 0) ? 1 : 0);
	p->padding = MAX(0, (p->min_length - p->printed));
	decimal = DABS(n); // DABS?
	decimal = (decimal - (long)(DABS(n))) * //DABS?
	ft_pow(10, p->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10; // rounding
	value = (long)decimal; // it was int
	padding(p, 0);
	ldtoa_fill(n, p, value); // why ld?
	padding(p, 1);
}
