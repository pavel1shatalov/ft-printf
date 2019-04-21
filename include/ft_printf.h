/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggerhold <ggerhold@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:29:14 by ggerhold          #+#    #+#             */
/*   Updated: 2019/04/21 20:41:54 by ggerhold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define MAX(a, b)		b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)		a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)			(a < 0) ? -a : a
# define DABS(a)		(a < 0.0f) ? -a : a

# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS			(1 << 2)
# define F_MINUS		(1 << 3)
# define F_ZERO			(1 << 4)
# define F_UPCASE		(1 << 5)
# define F_SHORT		(1 << 6)
# define F_SHORT2		(1 << 7)
# define F_LONG			(1 << 8)
# define F_LONG2		(1 << 9)
# define F_APP_PRECI	(1 << 10)
# define F_POINTER		(1 << 11)
# define PF_BUF_SIZE	64

typedef struct			s_printf
{
	int					len;
	short				f;
	short				n;
	int					min_length;
	int					precision;
	int					padding;
	int					printed;
	int					fd;
	int					buffer_index;
	char				buff[PF_BUF_SIZE];
	va_list				ap;
	char				*format;
	unsigned			c;
}						t_printf;

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);

void					parse_optionals(t_printf *p);
void					cs_not_found(t_printf *p);

void					pf_putnb(t_printf *p);
void					pf_putnb_base(int base, t_printf *p);
void					itoa_printf(long long d, t_printf *p, int len);
void					itoa_base_printf(unsigned long long d, int b, t_printf *p);
void					itoa_base_fill(unsigned long long tmp, int base, char *str,
						t_printf *p);
void					pf_putdouble(t_printf *p);
void					print_pointer_address(t_printf *p);


void					pf_putstr(t_printf *p);
void					pf_character(t_printf *p, unsigned c);
void					ft_printf_putstr(char *s, t_printf *p);

void					buffer(t_printf *p, void *new_elem, size_t size);
void					padding(t_printf *p, int n);

#endif
