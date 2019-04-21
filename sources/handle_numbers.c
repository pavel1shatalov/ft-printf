/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 21:58:44 by ggerhold          #+#    #+#             */
/*   Updated: 2019/04/21 21:58:46 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// we've nailed it besides the comments

void	pf_putnb(t_printf *p)
{
	long long	n;

	if (p->f & F_LONG || p->f & F_LONG2)
		n = (p->f & F_LONG2) ? ((long long)va_arg(p->ap, long long)) :
			((long long)va_arg(p->ap, long));
	else if (p->f & F_SHORT || p->f & F_SHORT2)
		n = (p->f & F_SHORT2) ? (long long)((char)va_arg(p->ap, int)) :
			(long long)((short)va_arg(p->ap, int));
	else
		n = ((long long)va_arg(p->ap, int));
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	itoa_printf(n, p, 0);
}

void	pf_putnb_base(int base, t_printf *p)
{
	unsigned long long	n;

	if (p->f & F_LONG || p->f & F_LONG2)
		n = (p->f & F_LONG2) ? ((unsigned long long)va_arg(p->ap, unsigned long long)) :
			((unsigned long long)va_arg(p->ap, unsigned long));
	else if (p->f & F_SHORT || p->f & F_SHORT2)
		n = (p->f & F_SHORT2) ? (unsigned long long)((unsigned char)va_arg(p->ap, int))
			: (unsigned long long)((unsigned short)va_arg(p->ap, int));
	else
		n = (unsigned long long)va_arg(p->ap, unsigned int);
	itoa_base_printf(n, base, p);
}

void	itoa_printf(long long n, t_printf *p, int len)
{
	char				s[21];
	unsigned long long	tmp;

	tmp = ABS(n);
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	if ((n < 0 || p->f & F_PLUS || p->f & F_SPACE) && p->f & F_ZERO)
		--p->precision;
	p->printed = MAX(len, p->precision);
	if (n < 0 || p->f & F_PLUS || p->f & F_SPACE)
		++p->printed;
	p->padding = (p->printed > p->min_length) ? 0 : p->min_length - p->printed;
	padding(p, 0);
	tmp = ABS(n);
	itoa_base_fill(tmp, 10, s, p);
	(p->f & F_SPACE) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffer(p, s, p->printed);
	padding(p, 1);
}

void	itoa_base_printf(unsigned long long n, int b, t_printf *p) // check hexadecimal and binary
{
	unsigned long long	tmp;
	char				s[21];
	int					ext;

	p->printed = 0;
	tmp = n;
	while (tmp && ++p->printed)
		tmp /= b;
	(p->f & F_ZERO) ? p->precision = p->min_length : 0;
	ext = (p->printed >= p->precision) ? 0 : 1;
	p->printed = MAX(p->precision, p->printed);
	((p->f & F_SHARP) && b == 8 && !ext) ? --p->min_length : 0;
	((p->f & F_SHARP) && b == 8 && !n && (p->f & F_APP_PRECI)) ?
	++p->printed : 0;
	((p->f & F_SHARP) && b == 16 && !(p->f & F_ZERO)) ? p->min_length -= 2 : 0;
	p->padding = MAX(0, (p->min_length - p->printed));
	padding(p, 0);
	if ((n || (p->f & F_POINTER))
		&& (p->f & F_SHARP) && ((b == 8 && !ext) || (b == 16)))
		buffer(p, "0", 1);
	if ((n || (p->f & F_POINTER)) && (p->f & F_SHARP) && b == 16)
		buffer(p, (p->f & F_UPCASE) ? "X" : "x", 1);
	itoa_base_fill(n, b, s, p);
	buffer(p, s, p->printed);
	padding(p, 1);
}

void	itoa_base_fill(unsigned long long tmp, int b, char s[PF_BUF_SIZE], t_printf *p)
{
	int		len;

	if (tmp && !(p->f & F_POINTER) && (p->f & F_ZERO) && (p->f & F_SHARP) && // why so many conditions ?
	b == 16 && !(p->f & F_LONG2) && p->printed > 3)
		p->printed -= 2;
	len = p->printed;
	p->c = 'a' - 10 - ((p->f & F_UPCASE) >> 1);
	while (len--)
	{
		s[len] = tmp % b + ((tmp % b < 10) ? '0' : p->c);
		tmp /= b;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0; //what is going on?
}
