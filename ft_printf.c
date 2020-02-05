/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:19:42 by iariss            #+#    #+#             */
/*   Updated: 2020/01/17 13:40:24 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

int				ft_printf(const char *format, ...)
{
	t_format	r;
	t_lolo		x;

	x.i = 0;
	x.d = 0;
	x.p = NULL;
	x.lo = (char*)format;
	va_start(x.ap, format);
	if (x.lo)
	{
		while (x.lo[x.i] != '\0' && x.lo[x.i])
		{
			ft_rest(&x, &r);
			if (x.lo[x.i] != '%' && x.lo[x.i])
			{
				ft_wiz(x.lo[x.i], &x.d);
				x.i++;
			}
		}
		va_end(x.ap);
		return (x.d);
	}
	return (-1);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int				ft_small(t_format *r, va_list ap, t_lolo *x, int z)
{
	r->j = 0;
	r->flague = 0;
	r->w = -1;
	r->p = -1;
	r->a = 1;
	x->i = ft_new(r, ap, x);
	ft_redirect(r, ap, &x->d, &z);
	return (x->i);
}

void			ft_redirect(t_format *r, va_list ap, int *d, int *z)
{
	char		*h;

	if (r->data_type == 'c')
		ft_printc(va_arg(ap, int), r, d);
	else if (r->data_type == 's')
	{
		h = va_arg(ap, char*);
		if (h)
			ft_prints(h, r, d);
		else
			ft_prints("(null)", r, d);
	}
	else if (r->data_type == '%')
		ft_printc('%', r, d);
	else if (r->data_type == 'i' || r->data_type == 'd')
		ft_printn(va_arg(ap, int), r, d, z);
	else if (r->data_type == 'u')
		ft_printu(va_arg(ap, unsigned int), r, d);
	else if (r->data_type == 'x' || r->data_type == 'X')
		ft_printx(va_arg(ap, unsigned int), r, d);
	else if (r->data_type == 'p')
	{
		r->a = 1;
		ft_printp(va_arg(ap, unsigned long long), r, d);
	}
}

void			ft_condu2(int n, t_format *r, int *w, int *p)
{
	if ((r->j) && n)
	{
		(*p) = r->w - ft_numberlen(n);
		if (r->p == 0 || r->p == -1)
			(*w) = 0;
		else if (r->w && r->p > 0)
			(*p) = r->p - ft_numberlen(n);
	}
	if (r->p > r->w)
		(*w) = 0;
	if (n == 0 && r->p == 0)
	{
		(*w) = r->w;
		r->a--;
	}
	if (!r->o && n == 0 && r->p == -1)
	{
		r->w = r->w + 1;
		r->a--;
	}
}

void			ft_wn(t_format *r, t_lolo *x, va_list ap)
{
	r->w = va_arg(ap, int);
	x->i++;
	r->u = 1;
}
